package main

import (
	"fmt"
)

func firstUniqChar(s string) int {
	count := map[rune]int{}
	pos := map[rune]int{}
	slen := len(s)

	for i, c := range s {
		_, exists := count[c]
		if exists {
			count[c] += 1
		} else {
			count[c] = 1
		}
		pos[c] = i
	}

	minpos := slen + 1
	for k, v := range count {
		if v == 1 && pos[k] < minpos {
			minpos = pos[k]
		}
	}
	if minpos == slen+1 {
		return -1
	}
	return minpos
}

func main() {
	fmt.Println(firstUniqChar("abcdefg"))
}
