func triangleNumber(nums []int) int {
	numsLen := len(nums)
	sort.Ints(nums)
	var result int
	var j, k int
	for i, v := range nums {
		k = i
		for j = i + 1; j < numsLen; j++ {
			for ; k+1 < numsLen && nums[k+1] < v+nums[j]; k++ {
			}
			if k-j > 0 {
				result += k - j
			}
		}
	}
	return result
}
