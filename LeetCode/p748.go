/*
#include <string.h>
#include <ctype.h>
*/
import "C"

func shortestCompletingWord(licensePlate string, words []string) string {
	var lCount [26]int32
	for _, i := range strings.ToLower(licensePlate) {
		if C.isalpha(C.int(i)) != 0 {
			lCount[i-'a']++
		}
	}
	var sWordCount [26]int32
	minIdx := -1
	for idx, word := range words {
		C.memset(unsafe.Pointer(&sWordCount), 0, C.ulong(unsafe.Sizeof(sWordCount)))
		for _, ch := range word {
			sWordCount[ch-'a']++
		}
		f := true
		for i, v := range lCount {
			if v > sWordCount[i] {
				f = false
				break
			}
		}
		if f && (minIdx == -1 || len(word) < len(words[minIdx])) {
			minIdx = idx
		}
	}
	return words[minIdx]
}

