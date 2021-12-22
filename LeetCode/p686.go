func repeatedStringMatch(a string, b string) int {
	lenA := len(a)
	lenB := len(b)
	if lenA >= lenB {
		if strings.Index(a, b) != -1 {
			return 1
		} else if strings.Index(a+a, b) != -1 {
			return 2
		} else {
			return -1
…		} else {
			return l/lenA + 1
		}
	}
	return -1
}

