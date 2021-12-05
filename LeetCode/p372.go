const MOD = 1337

func intPow(a, x int) int {
	ans := 1
	a %= MOD
	for x != 0 {
		if (x & 1) != 0 {
			ans = ans * a % MOD
		}
		a = a * a % MOD
		x >>= 1
	}
	return ans
}

func superPow(a int, b []int) int {
	bLen := len(b)
	if bLen == 0 {
		return 1
	}

	return intPow(superPow(a, b[:bLen-1]), 10) % MOD * intPow(a, b[bLen-1]) % MOD
}

