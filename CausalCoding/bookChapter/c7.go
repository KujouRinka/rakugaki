package prac

import (
	"flag"
	"fmt"
	"log"
	"math"
	"net/http"
	"os"
	"strconv"
	"text/tabwriter"
	"time"
)

type baseItem struct {
	name     string
	price    int32
	quantity int32
}

type Book struct {
	baseItem
	author string
}

type Movie struct {
	baseItem
	publisher string
}

type Modifier interface {
	Price(newPrice int32) int32
	Name(newName string) string
}

func (item *baseItem) Price(newPrice int32) int32 {
	item.price = newPrice
	return newPrice
}

func (item *baseItem) Name(newName string) string {
	item.name = newName
	return newName
}

func fakeMain() {
	var b = Book{
		baseItem: baseItem{
			name:     "oliver",
			price:    100,
			quantity: 20,
		},
		author: "Kujou",
	}
	fmt.Println(b.name)
	changeName(&b, "twist")
	fmt.Println(b.name)
}

func changeName(i Modifier, newName string) {
	i.Name(newName)
}

// 7.4
type Celsius float64
type Fahrenheit float64
type Kelvins float64

func FToC(c Fahrenheit) Celsius {
	return Celsius(c*1.8 + 32)
}

func (c *Celsius) Write(b []byte) (int, error) {
	return 0, nil
}

func KToC(c Kelvins) Celsius {
	return Celsius(c - 274.15)
}

func (c Celsius) String() string {
	return fmt.Sprintf("%f C", c)
}

type celsiusFlag struct{ Celsius }

func (c *celsiusFlag) Set(s string) error {
	var unit string
	var value float64
	fmt.Sscanf(s, "%f%s", &value, &unit)
	switch unit {
	case "C":
		c.Celsius = Celsius(value)
		return nil
	case "F":
		c.Celsius = FToC(Fahrenheit(value))
		return nil
	case "K":
		c.Celsius = KToC(Kelvins(value))
		return nil
	}
	return fmt.Errorf("invalid temperature %q", s)
}

func CelsiusFlag(name string, value Celsius, usage string) *Celsius {
	f := celsiusFlag{value}
	flag.CommandLine.Var(&f, name, usage)
	return &f.Celsius
}

// 7.6
type Track struct {
	Title  string
	Artist string
	Album  string
	Year   int
	Length time.Duration
}

func length(s string) time.Duration {
	d, err := time.ParseDuration(s)
	if err != nil {
		panic(s)
	}
	return d
}

type byArtist []*Track

func (x byArtist) Len() int {
	return len(x)
}

func (x byArtist) Less(i, j int) bool {
	return x[i].Artist < x[j].Artist
}

func (x byArtist) Swap(i, j int) {
	x[i], x[j] = x[j], x[i]
}

func printTracks(tracks []*Track) {
	const format = "%v\t%v\t%v\t%v\t%v\t\n"
	tw := new(tabwriter.Writer).Init(os.Stdout, 0, 8, 2, ' ', 0)
	fmt.Fprintf(tw, format, "Title", "Artist", "Album", "Year", "Length")
	fmt.Fprintf(tw, format, "-----", "------", "-----", "----", "------")
	for _, t := range tracks {
		fmt.Fprintf(tw, format, t.Title, t.Artist, t.Album, t.Year, t.Length)
	}
	tw.Flush() // calculate column widths and print table
}

// 7.7
type dollar float32
type dataBase map[string]dollar

func (d dollar) String() string {
	return fmt.Sprintf("%.2f", d)
}

func (db dataBase) ServeHTTP(w http.ResponseWriter, req *http.Request) {
	switch req.URL.Path {
	case "/list":
		for item, price := range db {
			_, _ = fmt.Fprintf(w, "%s: %s\n", item, price)
		}
	case "/price":
		item := req.URL.Query().Get("item")
		price, ok := db[item]
		if !ok {
			w.WriteHeader(http.StatusNotFound)
			_, _ = fmt.Fprintf(w, "no such item: %q\n", item)
			return
		}
		_, _ = fmt.Fprintf(w, "%s\n", price)
	default:
		w.WriteHeader(http.StatusNotFound)
		_, _ = fmt.Fprintf(w, "no such page: %s\n", req.URL)
	}
}

func (db dataBase) list(w http.ResponseWriter, req *http.Request) {
	log.Println("get all items")
	for item, price := range db {
		fmt.Fprintf(w, "%s: %s\n", item, price)
	}
}

func (db dataBase) price(w http.ResponseWriter, req *http.Request) {
	item := req.URL.Query().Get("item")
	price, ok := db[item]
	log.Printf("get price of: %s\n", item)
	if !ok {
		w.WriteHeader(http.StatusNotFound)
		fmt.Fprintf(w, "no such item: %q\n", item)
		return
	}
	fmt.Fprintf(w, "%s\n", price)
}

func (db dataBase) update(w http.ResponseWriter, req *http.Request) {
	item := req.URL.Query().Get("item")
	price := req.URL.Query().Get("price")
	if _, ok := db[item]; !ok {
		w.WriteHeader(http.StatusNotFound)
		fmt.Fprintf(w, "no such item: %q\n", item)
		return
	}

	fPrice, err := strconv.ParseFloat(price, 32)
	if err != nil {
		w.WriteHeader(http.StatusNotFound)
		fmt.Fprintf(w, "price syntax error: %q\n", price)
		return
	}

	db[item] = dollar(fPrice)
	fmt.Fprintf(w, "success update price of %q: %q", item, price)
}

func lightServer() {
	db := dataBase{
		"shoes": 50,
		"socks": 1,
	}
	mux := http.NewServeMux()
	mux.Handle("/list", http.HandlerFunc(db.list))
	mux.Handle("/price", http.HandlerFunc(db.price))
	mux.Handle("/update", http.HandlerFunc(db.update))
	log.Fatal(http.ListenAndServe("127.0.0.1:8000", mux))
}

// 7.9
type Expr interface {
	Eval(env Env) float64
}

type Var string

type literal float64

type unary struct {
	op rune
	x  Expr
}

type binary struct {
	op   rune
	x, y Expr
}

type call struct {
	fn string
	args []Expr
}

type Env map[Var]float64

func (v Var) Eval(env Env) float64 {
	return env[v]
}

func (l literal) Eval(_ Env) float64 {
	return float64(l)
}

func (u unary) Eval (env Env) float64 {
	switch u.op {
	case '+':
		return +u.x.Eval(env)
	case '_':
		return -u.x.Eval(env)
	}
	panic(fmt.Sprintf("unsupported unary operator: %q", u.op))
}

func (b binary) Eval(env Env) float64 {
	switch b.op {
	case '+':
		return b.x.Eval(env) + b.y.Eval(env)
	case '-':
		return b.x.Eval(env) - b.y.Eval(env)
	case '*':
		return b.x.Eval(env) * b.y.Eval(env)
	case '/':
		return b.x.Eval(env) / b.y.Eval(env)
	}
	panic(fmt.Sprintf("unsupported binary operator: %q", b.op))
}

func (c call) Eval(env Env) float64 {
	switch c.fn {
	case "pow":
		return math.Pow(c.args[0].Eval(env), c.args[0].Eval(env))
	case "sin":
		return math.Sin(c.args[0].Eval(env))
	case "sqrt":
		return math.Sqrt(c.args[0].Eval(env))
	}
	panic(fmt.Sprintf("unsupported function call: %q", c.fn))
}
