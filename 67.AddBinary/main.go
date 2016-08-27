package main

import (
	"fmt"
)

func strToBinNum(n string) []byte {
	l := len(n)
	ret := make([]byte, l)
	for i, c := range n {
		ret[l-i-1] = byte(c) - 48
	}
	return ret
}

func binNumToStr(n []byte) string {
	l := len(n)
	for l > 1 && n[l-1] == 0 {
		l -= 1
	}
	ret := make([]rune, l)
	for i := 0; i < l; i++ {
		ret[l-i-1] = rune(n[i]) + 48
	}
	return string(ret)
}

func addBinary(a string, b string) string {
	anum := strToBinNum(a)
	bnum := strToBinNum(b)

	alen := len(anum)
	blen := len(bnum)
	clen := alen
	if alen < blen {
		clen = blen
	}
	cnum := make([]byte, clen+1)
	for i := 0; i < clen; i++ {
		if i >= alen {
			cnum[i] += bnum[i]
		} else if i >= blen {
			cnum[i] += anum[i]
		} else {
			cnum[i] += anum[i] + bnum[i]
		}

		if cnum[i] >= 2 {
			cnum[i] -= 2
			cnum[i+1] += 1
		}
	}
	return binNumToStr(cnum)
}

func main() {
	a := "000101011111011"
	b := "00011"
	fmt.Println(addBinary(a, b))
}
