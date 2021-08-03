func findUnsortedSubarray(nums []int) int {
	rMin, lMax := 0x7fffffff, -0x80000000
	numsLen := len(nums)
	rLeft, rRight := -1, -1
	for i := 0; i < numsLen; i++ {
		right, left := i, numsLen - i - 1
		if nums[left] > rMin {
			rLeft = left
		} else {
			rMin = nums[left]
		}

		if nums[right] < lMax {
			rRight = right
		} else {
			lMax = nums[right]
		}
	}

	if rLeft == -1 {
		return 0
	}
	return rRight - rLeft + 1
}
