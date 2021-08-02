func kWeakestRows(mat [][]int, k int) []int {
	m, n := len(mat), len(mat[0])
	visited := make(map[int]bool)
	var res []int
loop:
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if mat[j][i] == 0 && visited[j] == false {
				res = append(res, j)
				visited[j] = true
				k--
			}
			if k == 0 {
				break loop
			}
		}
	}
	for i := 0; i < m; i++ {
		if k == 0 {
			break
		}
		if visited[i] == false {
			res = append(res, i)
			k--
		}
	}
	return res
}
