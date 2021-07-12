package listing16

import (
	"fmt"
	"runtime"
	"sync"
)

var (
	counter int64

	wg    sync.WaitGroup
	mutex sync.Mutex
)

func f() {
	wg.Add(2)

	go incCounter(1)
	go incCounter(2)

	wg.Wait()
	fmt.Println("final counter:", counter)

}

func incCounter(id int) {
	defer wg.Done()

	for count := 0; count < 2; count++ {
		mutex.Lock()
		{
			value := counter
			runtime.Gosched()
			value++
			counter = value
		}
		mutex.Unlock()
	}
}
