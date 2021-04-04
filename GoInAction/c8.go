package main

import (
	"flag"
	"fmt"
	"io"
	"log"
	"net"
	"strconv"
	"time"
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
