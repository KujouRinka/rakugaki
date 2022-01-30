func uncommonFromSentences(s1 string, s2 string) []string {
	wordMap := make(map[string]int)
	for _, v := range append(strings.Split(s1, " "), strings.Split(s2, " ")...) {
		wordMap[v]++
	}
	result := make([]string, 0, len(wordMap)/5)
	for k, v := range wordMap {
		if v == 1 {
			result = append(result, k)
		}
	}
	return result
}

