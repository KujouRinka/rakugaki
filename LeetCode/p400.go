func findNthDigit(n int) int {
	numLen := 1
	powNum := 1
	for n-numLen*9*powNum > 0 {
		n -= numLen * 9 * powNum
		numLen++
		powNum *= 10
	}

	x := n/numLen - 1 + powNum
	n -= (x - powNum + 1) * numLen
	if n == 0 {
		return x % 10
	} else {
		return (x + 1) / int(math.Pow(10, float64(numLen-n))) % 10
	}
}
