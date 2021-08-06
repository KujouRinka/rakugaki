// though slower, but more clear, I think.
// replace both map and list to slice will run faster.
func shortestPathLength(graph [][]int) int {
	n := len(graph)
	q := list.List{}
	type tp struct{ u, mask, dis int }
	seen := make([]map[int]bool, n)
	for i := range seen {
		seen[i] = make(map[int]bool)
		seen[i][1<<i] = true
		q.PushBack(tp{i, 1 << i, 0})
	}

	for {
		t := q.Front()
		q.Remove(t)
		if t.Value.(tp).mask == (1<<n)-1 {
			return t.Value.(tp).dis
		}
		for _, v := range graph[t.Value.(tp).u] {
			tmpMask := t.Value.(tp).mask | (1 << v)
			if !seen[v][tmpMask] {
				seen[v][tmpMask] = true
				q.PushBack(tp{v, tmpMask, t.Value.(tp).dis + 1})
			}
		}
	}
}
