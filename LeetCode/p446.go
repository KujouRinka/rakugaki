func numberOfArithmeticSlices(nums []int) int {
	var result int
	f := make([]map[int]int, len(nums))
	for back, v1 := range nums {
		f[back] = make(map[int]int)
		for front, v2 := range nums[:back] {
			delta := v1 - v2
			tmp := f[front][delta]
			result += tmp
			f[back][delta] += tmp + 1
		}
	}

	return result
}
