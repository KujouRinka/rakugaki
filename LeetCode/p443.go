func compress(chars []byte) int {
	countRepeat := func(start int) int {
		cnt := 1
		last := chars[start]
		for _, ch := range chars[start+1:] {
			if ch != last {
				break
			}
			cnt++
		}
		return cnt
	}

	charsLen := len(chars)
	var changePtr int
	for i := 0; i < charsLen; {
		cnt := countRepeat(i)	// count repeat nums
		chars[changePtr] = chars[i]
		changePtr++
		if cnt != 1 {
			ns := strconv.Itoa(cnt)
			for _, ch := range ns {
				chars[changePtr] = byte(ch)
				changePtr++
			}
		}
		i += cnt
	}
	chars = chars[:changePtr]
	return changePtr
}
