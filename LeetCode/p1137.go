func tribonacci(n int) int {
	if n == 0 {
		return 0
	}
	if n == 1 || n == 2 {
		return 1
	}
	mat := [][]int{
		{1, 1, 1},
		{1, 0, 0},
		{0, 1, 0},
	}
	mat = matrixPow(mat, n-2)
	result := mat[0][0] + mat[0][1]
	return result
}

func matrixPow(base [][]int, n int) [][]int {
	if n == 0 {
		return [][]int{
			{1, 0, 0},
			{0, 1, 0},
			{0, 0, 1},
		}
	}
	if n == 1 {
		return base
	}

	if n&1 == 1 {
		return matrixMultiply(matrixPow(base, n-1), base)
	} else {
		t := matrixPow(base, n/2)
		return matrixMultiply(t, t)
	}
}

func matrixMultiply(a, b [][]int) [][]int {
	size := len(a)
	result := make([][]int, size)
	for i := range result {
		result[i] = make([]int, size)
		for j := 0; j < size; j++ {
			result[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j] + a[i][2]*b[2][j]
		}
	}
	return result
}
