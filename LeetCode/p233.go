func countDigitOne(n int) int {
	var result int
	for tmp, base := n, 1; tmp > 0; tmp /= 10 {
		var other int
		k := n % (base * 10)
		if k < base {
			other = 0
		} else {
			other = min(base, k-base+1)
		}
		result += (tmp/10)*base + other
		base *= 10
	}

	return result
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
