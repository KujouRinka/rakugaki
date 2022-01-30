var m_result int
var x_size int
var y_size int
var raw_data [][]int
var visited [][]bool

var dirs [][]int = [][]int{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}

func getMaximumGold(grid [][]int) int {
	m_result = 0
	raw_data = grid
	x_size = len(grid[0])
	y_size = len(grid)
	visited = make([][]bool, y_size)
	for i := range visited {
		visited[i] = make([]bool, x_size)
	}
	for i := 0; i < y_size; i++ {
		for j := 0; j < x_size; j++ {
			if raw_data[i][j] != 0 {
				visited[i][j] = true
				backtracking(j, i, raw_data[i][j])
				visited[i][j] = false
			}
		}
	}
	return m_result
}

func backtracking(x, y, sum int) {
	validDirs := getDirs(x, y)
	if validDirs == 0 {
		if m_result < sum {
			m_result = sum
		}
		return
	}
	for i := 0; i < 4; i++ {
		if (validDirs>>i)&1 != 0 {
			nx := x + dirs[i][0]
			ny := y + dirs[i][1]
			visited[ny][nx] = true
			backtracking(nx, ny, sum+raw_data[ny][nx])
			visited[ny][nx] = false
		}
	}
}

func getDirs(x, y int) uint {
	var d uint
	for i := 0; i < 4; i++ {
		nx := x + dirs[i][0]
		ny := y + dirs[i][1]
		if isValid(nx, ny) && raw_data[ny][nx] != 0 && !visited[ny][nx] {
			d |= 1 << i
		}
	}
	return d
}

func isValid(x, y int) bool {
	return x >= 0 && x < x_size && y >= 0 && y < y_size
}

