package main

import (
	"fmt"
	"strconv"
	"strings"
)

func maximumSwap(num int) int {
	str := strconv.Itoa(num)
	swap1 := -1
	swap2 := -1
	maxSwap2 := -1
	for i, _ := range str {
		for j := i + 1; j < len(str); j++ {
			if str[j] > str[i] && (maxSwap2 == -1 || str[j] >= str[maxSwap2]) {
				maxSwap2 = j
				// swap
				swap1 = i
				swap2 = j
			}
		}
		if swap1 != -1 {
			goto end
		}
	}
end:
	if swap1 == -1 {
		return num
	}
	builder := &strings.Builder{}
	builder.WriteString(str[:swap1])
	builder.WriteByte(str[swap2])
	builder.WriteString(str[swap1+1 : swap2])
	builder.WriteByte(str[swap1])
	builder.WriteString(str[swap2+1:])
	resultStr := builder.String()
	result, _ := strconv.Atoi(resultStr)
	return result
}

func main() {
	fmt.Println(maximumSwap(2736))
	fmt.Println(maximumSwap(9973))
	fmt.Println(maximumSwap(2))
	fmt.Println(maximumSwap(1))
	fmt.Println(maximumSwap(99999999))
	fmt.Println(maximumSwap(123456789))
	fmt.Println(maximumSwap(912345678))
	fmt.Println(maximumSwap(1993))
}
