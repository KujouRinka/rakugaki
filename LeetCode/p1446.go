func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxPower(s string) int {
	pFront, pBack, sLen := 0, 0, len(s)
	maxSameLen := 0
	for pBack < sLen {
		for ; pBack < sLen && s[pFront] == s[pBack]; pBack++ {
		}
		maxSameLen = max(maxSameLen, pBack-pFront)
		pFront = pBack
	}
	return maxSameLen
}
