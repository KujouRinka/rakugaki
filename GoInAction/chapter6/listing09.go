package listing09

import (
	"fmt"
	"runtime"
	"sync"
)

var wg sync.WaitGroup

func f() {
	runtime.GOMAXPROCS(runtime.NumCPU())
	wg.Add(2)

	fmt.Println("Create goroutines")
	go printPrime("A")
	go printPrime("B")

	fmt.Println("waiting to finish")
	wg.Wait()
	fmt.Println("terminating program")
}

func printPrime(prefix string) {
	defer wg.Done()

next:
	for outer := 2; outer < 5000; outer++ {
		for inner := 2; inner < outer; inner++ {
			if outer%inner == 0 {
				continue next
			}
			fmt.Printf("%s:%d\n", prefix, outer)
		}
	}
	fmt.Println("completed", prefix)
}
