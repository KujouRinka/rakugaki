var result []string

func restoreIpAddresses(s string) []string {
	result = []string{}
	tmpRec := make([]string, 0, 4)
	backtracking(tmpRec, s, 0)
	return result
}

func backtracking(IPPart []string, s string, idx int) {
	if idx == len(s) {
		if len(IPPart) == 4 && isValid(IPPart) {
			result = append(result, strings.Join(IPPart, "."))
		}
		return
	}
	var builder strings.Builder
	builder.Grow(3)
	for builder.Len() <= 3 && idx < len(s) {
		builder.WriteByte(s[idx])
		idx++
		if builder.String()[0] == '0' && builder.Len() > 1 {
			return
		}
		IPPart = append(IPPart, builder.String())
		backtracking(IPPart, s, idx)
		IPPart = IPPart[:len(IPPart)-1]
	}
}

func isValid(IPPart []string) bool {
	if len(IPPart) != 4 {
		return false
	}
	for _, v := range IPPart {
		if n, _ := strconv.Atoi(v); n > 255 {
			return false
		}
	}
	return true
}

