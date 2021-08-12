func longestPalindromeSubseq(s string) int {
	sLen := len(s)
	dp := make([][]int, sLen)
	for i := range dp {
		dp[i] = make([]int, sLen)
		dp[i][i] = 1
	}

	for i := sLen; i >= 0; i-- {
		for j := i + 1; j < sLen; j++ {
			if s[i] == s[j] {
				dp[i][j] = dp[i+1][j-1] + 2
			} else {
				dp[i][j] = max(dp[i+1][j], dp[i][j-1])
			}
		}
	}
	return dp[0][sLen-1]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
