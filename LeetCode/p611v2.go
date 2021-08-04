func triangleNumber(nums []int) int {
	numsLen := len(nums)
	sort.Ints(nums)
	var result int
	for i := 0; i < numsLen-1; i++ {
		var j, k int
		j = i + 2
		for j = i + 1; j < numsLen; j++ {
			for ; k < numsLen; {
				if nums[i] + nums[j] > nums[k] {
					k++
				} else {
					break
				}
			}
			if k - j - 1 > 0 {
				result += k - j - 1
			}
		}
	}
	return result
}
