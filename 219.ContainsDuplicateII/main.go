package main

import (
	"fmt"
)

func containsNearbyDuplicate(nums []int, k int) bool {
	nlen := len(nums)
	for i, v := range nums {
		for j := i + 1; j < nlen && j <= i+k; j++ {
			if v == nums[j] {
				return true
			}
		}
	}
	return false
}

func main() {
	n := []int{1, 2, 3, 4, 5, 6}
	k := 2
	fmt.Println(containsNearbyDuplicate(n, k))
}
