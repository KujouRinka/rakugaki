func eventualSafeNodes(graph [][]int) []int {
	n := len(graph)
	head := make([]int, n)
	es, next := make([]int, n*4), make([]int, n*4)
	for i := range head {
		head[i] = -1
	}
	for i := range next {
		es[i] = -1
		next[i] = -1
	}
	var ind int
	var add func(u, v int)
	add = func(u, v int) {
		es[ind] = v
		next[ind] = head[u]
		head[u] = ind
		ind++
	}

	inCount := make([]int, n)
	for i, s := range graph {
		for _, v := range s {
			add(v, i)
			inCount[i]++
		}
	}

	l := list.List{}
	for i, v := range inCount {
		if v == 0 {
			l.PushBack(i)
		}
	}

	for l.Len() != 0 {
		hd := l.Back().Value.(int)
		l.Remove(l.Back())
		for i := head[hd]; i != -1; i = next[i] {
			v := es[i]
			inCount[v]--
			if inCount[v] == 0 {
				l.PushBack(v)
			}
		}
	}

	var res []int
	for i, v := range inCount {
		if v == 0 {
			res = append(res, i)
		}
	}
	return res
}
