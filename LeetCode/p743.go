func networkDelayTime(times [][]int, n int, k int) int {
	// n: node quantity, k: sender
	g := make([][]uint16, n)
	for i := 0; i < n; i++ {
		g[i] = make([]uint16, n)
		for j := 0; j < n; j++ {
			g[i][j] = uint16(0x7fff)
		}
	}
	for _, val := range times {
		from, to := val[0], val[1]
		g[from-1][to-1] = uint16(val[2])
	}

	Set := make([]bool, n)
	Dst := make([]uint16, n)
	for i := range Dst {
		Dst[i] = 0x7fff
	}
	Dst[k-1] = 0

	for {
		minDstInDst := uint16(0x7fff)
		minIndOfNode := -1
		for i, v := range Dst {
			if Set[i] == false && v < minDstInDst {
				minDstInDst = v
				minIndOfNode = i
			}
		}
		if minIndOfNode == -1 {
			break
		}
		Set[minIndOfNode] = true

		for i := 0; i < n; i++ {
			if g[minIndOfNode][i]+minDstInDst < Dst[i] {
				Dst[i] = g[minIndOfNode][i] + minDstInDst
			}
		}
	}

	max := uint16(0)
	for _, v := range Dst {
		if v > max {
			max = v
		}
	}

	if max == 0x7fff {
		return -1
	} else {
		return int(max)
	}
}
