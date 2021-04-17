package prac

import (
	"bufio"
	"flag"
	"fmt"
	"github.com/adonovan/gopl.io/ch8/thumbnail"
	"io"
	"io/ioutil"
	"log"
	"net"
	"net/http"
	"os"
	"path/filepath"
	"strconv"
	"strings"
	"sync"
	"time"
	"x.org/x/net/html"
)

// 8.2
type port uint16

func (p port) String() string {
	return fmt.Sprintf("%d", p)
}

func (p *port) Set(s string) error {
	tp, err := strconv.Atoi(s)
	if err != nil {
		return fmt.Errorf("port: format error")
	}
	if tp > ((1 << 16) - 1) {
		return fmt.Errorf("port: too big")
	}
	*p = port(tp)
	return nil
}

func PortFlag(name string, value port, usage string) *port {
	flag.CommandLine.Var(&value, name, usage)
	return &value
}

var inPort = PortFlag("port", 8000, "server port")

func startTimeServer() {
	flag.Parse()
	listener, err := net.Listen("tcp", "localhost:" + inPort.String())
	fmt.Printf("working on port: %s\n", *inPort)
	if err != nil {
		log.Fatal(err)
	}
	for {
		conn, err := listener.Accept()
		fmt.Println("got conn from", conn.RemoteAddr())
		if err != nil {
			log.Print(err)
			continue
		}
		go handleConn(conn)
	}
}
func handleConn(c net.Conn) {
	defer c.Close()
	for {
		_, err := io.WriteString(c, time.Now().Format("15:04:05\n"))
		if err != nil {
			return
		}
		time.Sleep(1 * time.Second)
	}
}

// 8.3
func echoServer() {
	listener, err := net.Listen("tcp", "localhost:8000")
	if err != nil {
		log.Fatalln(err)
	}
	defer listener.Close()

	for {
		client, err := listener.Accept()
		fmt.Printf("got connection from %s\n", client.RemoteAddr())
		if err != nil {
			fmt.Println(err)
			continue
		}
		go handleConnection(client)
	}
}

func echo(w io.Writer, shout string, delay time.Duration) {
	fmt.Fprintln(w, "\t", strings.ToUpper(shout))
	time.Sleep(delay)
	fmt.Fprintln(w, "\t", shout)
	time.Sleep(delay)
	fmt.Fprintln(w, "\t", strings.ToLower(shout))
}

func handleConnection(c net.Conn) {
	defer c.Close()
	input := bufio.NewScanner(c)
	for input.Scan() {
		go echo(c, input.Text(), 1 * time.Second)
	}
}

// 8.5
func makeThumbnails(filenames []string) (thumbFiles []string, err error) {
	type item struct {
		thumbFile string
		err       error
	}
	done := make(chan *item, len(filenames))
	for _, filename := range filenames {
		go func(f string) {
			var it item
			it.thumbFile, it.err = thumbnail.ImageFile(f)
			done <- &it
		}(filename)
	}

	for range filenames {
		it := <-done
		if it.err != nil {
			return nil, it.err
		}
		thumbFiles = append(thumbFiles, it.thumbFile)
	}

	return thumbFiles, nil
}

// 8.6
func mT2() {
	filenames := []string{
		"sh.000520.jpg",
		"sh.600006.jpg",
		"sh.600016.jpg",
	}

	file := make(chan string, len(filenames))

	for _, filename := range filenames {
		file <- filename
	}

	close(file)

	n := makeThumbnails2(file)

	fmt.Println(n)
}

func makeThumbnails2(filename <-chan string) int64 {
	sizes := make(chan int64)
	var wg sync.WaitGroup
	for f := range filename {
		wg.Add(1)
		go func(f string) {
			defer wg.Done()
			thumb, err := thumbnail.ImageFile(f)
			if err != nil {
				log.Println(err)
				return
			}
			info, _ := os.Stat(thumb)
			sizes <- info.Size()
		}(f)
	}

	go func() {
		wg.Wait()
		close(sizes)
	}()

	var total int64
	for size := range sizes {
		total += size
	}
	return total
}


func calSquare() {
	naturals := make(chan int)
	squares := make(chan int)
	var now = time.Now()
	go func() {
		for i := 0; i < 100; i++ {
			naturals <- i
		}
		close(naturals)
	}()

	go func() {
		for nar := range naturals {
			squares <- nar * nar
		}
		close(squares)
	}()

	for x := range squares {
		fmt.Println(x)
	}
	fmt.Println(time.Since(now).Seconds())
}


func squrev2() {
	naturals := make(chan int)
	squares := make(chan int)
	go natural(naturals)
	go square(squares, naturals)
	printer(squares)
}

func natural(out chan<- int) {
	for i := 0; i < 100; i++ {
		out <- i
	}
	close(out)
}

func square(out chan<- int, in <-chan int) {
	for natural := range in {
		out <- natural * natural
	}
	close(out)
}

func printer(in <-chan int) {
	for res := range in {
		fmt.Println(res)
	}
}

// 8.4
func echoServer3() {
	listener, err := net.Listen("tcp", "localhost:8000")
	if err != nil {
		log.Fatalln(err)
	}

	for {
		conn, err := listener.Accept()
		fmt.Printf("got connection from %s\n", conn.RemoteAddr())
		if err != nil {
			log.Println(err)
			continue
		}
		go handleConn3(conn)
	}
}

func handleConn3(conn net.Conn) {
	defer conn.Close()
	input := bufio.NewScanner(conn)
	var wg sync.WaitGroup
	for input.Scan() {
		wg.Add(1)
		go func(msg string, delay time.Duration) {
			defer wg.Done()
			fmt.Fprintln(conn, "\t", strings.ToUpper(msg))
			time.Sleep(delay)
			fmt.Fprintln(conn, "\t", msg)
			time.Sleep(delay)
			fmt.Fprintln(conn, "\t", strings.ToLower(msg))
		}(input.Text(), 1 * time.Second)
	}

	fmt.Println("reach waiting")
	wg.Wait()
}

// 8.5
var maxStack int
var total int

func main() {
	seen := make(map[string]bool)
	worklist := make(chan []string)
	var pending int

	maxStack, _ = strconv.Atoi(os.Args[1])
	go func() {
		worklist <- os.Args[2:]
	}()

	pending++
	var stack int
	for ; pending > 0; pending-- {
		list := <-worklist
		stack++
		for _, link := range list {
			if !seen[link] {
				seen[link] = true
				pending++
				go func(link string) {
					worklist <- craw(link, stack)
				}(link)
			}
		}
	}
	fmt.Println(total)
}

var token = make(chan int, 20)

func craw(url string, stack int) []string {
	fmt.Println(url)
	total++
	token <- 1
	var list []string
	var err error
	if stack != maxStack {
		list, err = Extract(url)
	} else {
		list = []string{}
		err = fmt.Errorf("reach max stack")
	}
	<-token
	if err != nil {
		log.Println(err)
	}
	return list
}

func Extract(url string) ([]string, error) {
	resp, err := http.Get(url)
	if err != nil {
		return nil, err
	}
	if resp.StatusCode != http.StatusOK {
		resp.Body.Close()
		return nil, fmt.Errorf("getting %s: %s", url, resp.Status)
	}
	doc, err := html.Parse(resp.Body)
	resp.Body.Close()
	if err != nil {
		return nil, fmt.Errorf("parsing %s as HTML: %v", url, err)
	}
	var links []string
	visitNode := func(n *html.Node) {
		if n.Type == html.ElementNode && n.Data == "a" {
			for _, a := range n.Attr {
				if a.Key != "href" {
					continue
				}
				link, err := resp.Request.URL.Parse(a.Val)
				if err != nil {
					continue // ignore bad URLs
				}
				links = append(links, link.String())
			}
		}
	}
	forEachNode(doc, visitNode, nil)
	return links, nil
}

func forEachNode(n *html.Node, pre, post func(n *html.Node)) {
	if pre != nil {
		pre(n)
	}
	for c := n.FirstChild; c != nil; c = c.NextSibling {
		forEachNode(c, pre, post)
	}
	if post != nil {
		post(n)
	}
}

// 8.8
func echoServer4() {
	listener, err := net.Listen("tcp", "localhost:8000")
	if err != nil {
		log.Fatalln(err)
	}

	for {
		conn, err := listener.Accept()
		fmt.Printf("got connection from %s\n", conn.RemoteAddr())
		if err != nil {
			log.Println(err)
			continue
		}
		go handleConn4(conn)
	}
}

func handleConn4(conn net.Conn) {
	defer conn.Close()
	input := bufio.NewScanner(conn)
	var wg sync.WaitGroup
	refresh := make(chan int)
	go func() {
		for {
			select {
			case <-refresh:
			case <-time.After(10 * time.Second):
				cw := conn.(*net.TCPConn)
				cw.CloseWrite()
			}
		}
	}()

	for input.Scan() {
		refresh <- 1
		wg.Add(1)
		go func(msg string, delay time.Duration) {
			defer wg.Done()
			fmt.Fprintln(conn, "\t", strings.ToUpper(msg))
			time.Sleep(delay)
			fmt.Fprintln(conn, "\t", msg)
			time.Sleep(delay)
			fmt.Fprintln(conn, "\t", strings.ToLower(msg))
		}(input.Text(), 1 * time.Second)
	}

	fmt.Println("reach waiting")
	wg.Wait()
}

// 8.8.1
func pathSize() {
	fileSize := make(chan int64)
	var totalSize int64
	go func() {
		walkDir("F:\\books", fileSize)
		close(fileSize)
	}()
	for size := range fileSize {
		totalSize += size
	}
	fmt.Println("total size: ", totalSize)
}

func walkDir(dir string, fileSize chan<- int64) {
	for _, entry := range dirents(dir) {
		if entry.IsDir() {
			subdir := filepath.Join(dir, entry.Name())
			walkDir(subdir, fileSize)
		} else {
			fileSize <- entry.Size()
		}
	}
}

func dirents(dir string) []os.FileInfo {
	entries, err := ioutil.ReadDir(dir)
	if err != nil {
		fmt.Fprintf(os.Stderr, "dvl: %v\n", err)
		return nil
	}
	return entries
}
