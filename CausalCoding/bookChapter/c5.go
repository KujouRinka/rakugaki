package prac

import (
	"fmt"
	"log"
	"net/http"
	"os"
	"sort"
	"x.org/x/net/html"
)

func statisticElement(url string) {
	record := make(map[string]int)
	page, err := http.Get(url)
	if err != nil {
		fmt.Fprintf(os.Stderr, "%v\n", nil)
		return
	}

	pageRoot, err := html.Parse(page.Body)
	page.Body.Close()
	if err != nil {
		fmt.Fprintf(os.Stderr, "%v\n", nil)
		return
	}

	var keySlice []string
	deepVisit(pageRoot, record)
	for key := range record {
		keySlice = append(keySlice, key)
	}
	sort.Strings(keySlice)

	for _, key := range keySlice {
		fmt.Println(key, record[key])
	}
}

func deepVisit(node *html.Node, recordPtr map[string]int) {
	if node.Type == html.ElementNode {
		recordPtr[node.Data]++
	}
	for next := node.FirstChild; next != nil; next = next.NextSibling {
		deepVisit(next, recordPtr)
	}
}

func visitP(startURL string, maxURL int) {
	var queue []string
	var visited = make(map[string]bool)
	var nowURL = 0
	var bVisit func(url string)

	bVisit = func(url string) {
		if nowURL == maxURL {
			return
		}

		if visited[url] == false {
			visited[url] = true
			resp, err := http.Get(url)
			if err == nil {
				nowURL++
				fmt.Println(url)
				newURL, err := parseURL(resp)
				if err == nil {
					queue = append(queue, newURL...)
				}
			}
		}
		if len(queue) == 0 || len(queue) == 1{
			log.Println("No more URL")
			return
		}
		queue = queue[1:]
		bVisit(queue[0])
	}

	bVisit(startURL)
}

func parseURL(response *http.Response) ([]string, error) {
	var returnList []string
	node, err := html.Parse(response.Body)
	if err != nil {
		return nil, fmt.Errorf("Parse URL Error\n")
	}
	response.Body.Close()

	var f func(startNode *html.Node)
	f = func(startNode *html.Node) {
		if startNode.Type == html.ElementNode && startNode.Data == "a" {
			for _, attr := range startNode.Attr {
				if attr.Key == "href" {
					returnList = append(returnList, attr.Val)
				}
			}
		}
		for this := startNode.FirstChild; this != nil; this = this.NextSibling {
			f(this)
		}
	}

	f(node)

	return returnList, nil
}

// uva572
func oilDeposits() {
	var pic [][]byte
	var row, line = -1, -1
	var tmp string

	f, err := os.Open("read.in")
	defer f.Close()
	if err != nil {
		log.Fatalln(err)
	}
	os.Stdin = f
	for {
		fmt.Scan(&row, &line)
		if row == 0 {
			break
		}
		pic = [][]byte{}
		for i := 0; i < row; i++ {
			fmt.Scan(&tmp)
			pic = append(pic, []byte(tmp))
		}
		var piece = oilExplore(pic, row, line)
		fmt.Println(piece)
	}
}

func oilExplore(pic [][]byte, maxRow, maxLine int) int {
	var piece int

	var f func(row, line int)
	f = func(row, line int) {
		if row >= maxRow || line >= maxLine || row < 0 || line < 0 {
			return
		}
		if pic[row][line] != '@' {
			return
		}
		pic[row][line] = '*'
		f(row-1, line-1)
		f(row-1, line)
		f(row-1, line+1)
		f(row, line-1)
		f(row, line+1)
		f(row+1, line-1)
		f(row+1, line)
		f(row+1, line+1)
	}

	for i := 0; i < maxRow; i++ {
		for j := 0; j < maxLine; j++ {
			if pic[i][j] == '@' {
				f(i, j)
				piece++
			}
		}
	}
	return piece
}
