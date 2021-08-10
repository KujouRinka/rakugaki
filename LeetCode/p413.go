func numberOfArithmeticSlices(nums []int) int {
	var result int
	start, end, numsLen := 0, 1, len(nums)
	for end < numsLen {
		delta := nums[end] - nums[end-1]
		for ; end < numsLen; end++ {
			if delta != nums[end] - nums[end-1] {
				break
			}
		}
		if length := end - start; length >= 3 {
			result += countOfArray(length)
		}
		start = end - 1
	}

	return result
}

func countOfArray(length int) int {
	head := 1
	tail := length - 2
	items := tail - head + 1
	return (head + tail) * items / 2
}
