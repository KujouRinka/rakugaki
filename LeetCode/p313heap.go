type intHeap []int

func (i intHeap) Len() int {
	return len(i)
}

func (i intHeap) Less(a, b int) bool {
	return i[a] < i[b]
}

func (i intHeap) Swap(a, b int) {
	i[a], i[b] = i[b], i[a]
}

func (i *intHeap) Pop() interface{} {
	t := len(*i) - 1
	x := (*i)[t]
	*i = (*i)[:t]
	return x
}

func (i *intHeap) Push(x interface{}) {
	*i = append(*i, x.(int))
}

func nthSuperUglyNumber(n int, primes []int) int {
	seen := map[int]bool{1: true}
	hp := &intHeap{}
	heap.Init(hp)
	heap.Push(hp, 1)
	
	var ugly int
	for i := 0; i < n; i++ {
		ugly = heap.Pop(hp).(int)
		for _, prime := range primes {
			if now := ugly * prime; !seen[now] {
				heap.Push(hp, now)
				seen[now] = true
			}
		}
	}
	return ugly
}
