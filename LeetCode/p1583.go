func unhappyFriends(n int, preferences [][]int, pairs [][]int) int {
	d := make([][]int, n)
	for i, s := range preferences {
		d[i] = make([]int, n)
		for j, v := range s {
			d[i][v] = j
		}
	}

	happy := func(x, y int) bool {
		thisPre := d[x][y]
		for _, thatPair := range pairs {
			u, v := thatPair[0], thatPair[1]
            if u == x || v == x {
                continue
            }
			if d[x][u] < thisPre && d[u][x] < d[u][v] {
				return false
			}
			if d[x][v] < thisPre && d[v][x] < d[v][u] {
				return false
			}
		}
		return true
	}

	var result int
	for _, thisPair := range pairs {
		if !happy(thisPair[0], thisPair[1]) {
			result++
		}
		if !happy(thisPair[1], thisPair[0]) {
			result++
		}
	}

	return result
}
