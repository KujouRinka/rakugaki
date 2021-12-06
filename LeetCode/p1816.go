func truncateSentence(s string, k int) string {
	sLen := len(s)
	var wordCount int
	var frontPtr int
	for ; frontPtr < sLen && wordCount < k; wordCount++ {
		for ; frontPtr < sLen && s[frontPtr] != ' '; frontPtr++ {
		}
		frontPtr++
	}
	return s[:frontPtr-1]
}

