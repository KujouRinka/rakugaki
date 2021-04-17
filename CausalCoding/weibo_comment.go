// 同学大学生建模竞赛要用微博评论，举手之劳随手写了一个
// 前几天刚学习了 golang 的并发，顺便用来练练手
package main

import (
	"bytes"
	"fmt"
	"log"
	"net/http"
	"os"
	"regexp"
	"sync"
	"time"
)

var ch = make(chan int, 5)

func main() {
	var UA = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.72 Safari/537.36 Edg/90.0.818.39"
	var Cookie = "_T_WM=a6a9a364e025c1810824986a712d85b6; SUB=_2A25NfjcHDeRhGeFK6FQQ8C7OzTWIHXVugVlPrDV6PUJbktANLVrukW1NQ3n-EEt5PQjrzEwOrTt6XTdKZKhw-fks; SUBP=0033WrSXqPxfM725Ws9jqgMF55529P9D9WF1LY10avHED9l_Up1R-AkO5NHD95QNSheceK57eoq4Ws4DqcjMi--NiK.Xi-2Ri--ciKnRi-zNS0B0So27ehzc1Btt"
	var url = "https://weibo.cn/5254886684/Kbi6KikZB?type=comment&rand=612130&page=%d"

	var wg sync.WaitGroup
	startTime := time.Now()
	ticker := time.Tick(time.Second)
	filePath := "F:\\Project\\CodeProject\\Go\\src\\testProject\\secondBuild\\comment.txt"
	output, err := os.OpenFile(filePath, os.O_APPEND, 0666)

	if err != nil {
		log.Println(err)
		output = os.Stdout
	}

	var commentPages = 20
	var completePages int
	go func() {
		for _ = range ticker {
			fmt.Printf("%d of %d finished\n", completePages, commentPages)
		}
	}()

	for i := 1; i <= commentPages; i++ {
		req, _ := http.NewRequest("GET", fmt.Sprintf(url, i), nil)
		req.Header.Set("User-Agent", UA)
		req.Header.Set("Cookie", Cookie)
		ch <- 1
		wg.Add(1)
		go func(page int) {
			readComment(req, page, &wg, output)
			completePages++
		}(i)
	}

	wg.Wait()
	output.Close()

	fmt.Println("finished! use time of", time.Since(startTime))
}

func readComment(req *http.Request, page int, wg *sync.WaitGroup, output *os.File) {
	defer func() {
		<-ch
		wg.Done()
	}()

	response, err := (&http.Client{}).Do(req)
	if err != nil {
		log.Printf("get page %d error\n", page)
		return
	}

	var buf bytes.Buffer
	_, err = buf.ReadFrom(response.Body)
	if err != nil {
		log.Printf("read body of page %d error\n", page)
		return
	}
	response.Body.Close()

	namePattern, _ := regexp.Compile(`<a href="/u/\d+">(.*?)</a>`)
	commentPattern, _ := regexp.Compile(`<span class="ctt">(.*?)</span>`)
	subPattern, _ := regexp.Compile(`<.*?>`)

	names := namePattern.FindAll(buf.Bytes(), -1)
	comments := commentPattern.FindAll(buf.Bytes(), -1)

	_, err = fmt.Fprintf(output, "\ngetting page of %d\n", page)
	if err != nil {
		log.Println(err)
	}
	for index, name := range names {
		rName := subPattern.ReplaceAll(name, []byte{})
		rComment := subPattern.ReplaceAll(comments[index], []byte{})
		_, err = fmt.Fprintf(output, "%s: %s\n", rName, rComment)
		if err != nil {
			fmt.Println(err)
		}
	}
}
