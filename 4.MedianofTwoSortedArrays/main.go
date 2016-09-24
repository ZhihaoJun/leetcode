package main

import (
	"fmt"
)

func merge(nums1 []int, nums2 []int) []int {
	len1 := len(nums1)
	len2 := len(nums2)
	i := 0
	j := 0
	merged := []int{}

	for {
		if i < len1 && j < len2 {
			if nums1[i] < nums2[j] {
				merged = append(merged, nums1[i])
				i++
			} else {
				merged = append(merged, nums2[j])
				j++
			}
		} else if i < len1 {
			merged = append(merged, nums1[i])
			i++
		} else if j < len2 {
			merged = append(merged, nums2[j])
			j++
		} else {
			break
		}
	}
	return merged
}

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	m := merge(nums1, nums2)
	lenm := len(m)
	if lenm == 0 {
		return 0
	}
	mid := lenm / 2
	if lenm%2 == 0 {
		return (float64(m[mid]) + float64(m[mid-1])) / 2.0
	}
	return float64(m[mid])
}

func main() {
	nums1 := []int{1, 3, 4, 5, 8, 10}
	nums2 := []int{2, 3, 5, 9, 22}
	fmt.Println(findMedianSortedArrays(nums1, nums2))
}
