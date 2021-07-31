func titleToNumber(columnTitle string) int {
	var result int
	for i := range columnTitle {
		result *= 26
		result += int(columnTitle[i]) - int('A') + 1
	}
	return result
}
