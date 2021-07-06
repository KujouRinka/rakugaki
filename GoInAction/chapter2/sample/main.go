package main

import (
	"log"
	"os"
	"sample/search"
)

func init() {
	log.SetOutput(os.Stdout)
}

func main() {
	search.Run("president")
}
