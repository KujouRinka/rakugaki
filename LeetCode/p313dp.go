func nthSuperUglyNumber(n int, primes []int) int {
	primesLen := len(primes)
	dp := make([]int, n+1)
	pointers := make([]int, primesLen)

	dp[1] = 1
	for i := range pointers {
		pointers[i] = 1
	}

	for i := 2; i <= n; i++ {
		minVal := 0x7fffffff
		nums := make([]int, primesLen)
		for j, v := range pointers {
			var tmpVal int
			if tmpVal = dp[v] * primes[j]; tmpVal < minVal {
				minVal = tmpVal
			}
			nums[j] = tmpVal
		}
		dp[i] = minVal
		for j, val := range nums {
			if val <= minVal {
				pointers[j]++
			}
		}
	}

	return dp[n]
}
