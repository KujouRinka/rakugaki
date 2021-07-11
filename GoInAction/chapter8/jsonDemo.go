package jsonDemo

import (
	"bytes"
	"encoding/json"
	"fmt"
	"os"
)

type Contact struct {
	Name    string `json:"name"`
	Title   string `json:"title"`
	Contact struct {
		Home string `json:"home"`
		Cell string `json:"cell"`
	} `json:"contact"`
}

var JSON = `{
    "name": "Gopher",
    "title": "programmer",
    "contact": {
        "home": "451.333.3333",
        "cell": "415.555.5555"
    }
}`

func jsonDemo() {
	file, _ := os.OpenFile("test.json", os.O_CREATE|os.O_WRONLY, 0666)
	defer file.Close()
	var c1, c2 Contact
	var c map[string]interface{}
	var buffer bytes.Buffer
	buffer.WriteString(JSON)
	json.NewDecoder(&buffer).Decode(&c1)
	json.Unmarshal([]byte(JSON), &c2)
	json.Unmarshal([]byte(JSON), &c)
	fmt.Println(c1)
	fmt.Println(c2)
	fmt.Println(c)
	fmt.Println(c["name"], c["title"])
	fmt.Println(c["contact"].(map[string]interface{})["home"])
	fmt.Println(c["contact"].(map[string]interface{})["cell"])
	encoder := json.NewEncoder(file)
	encoder.SetIndent("", "    ")
	encoder.Encode(c)
}
