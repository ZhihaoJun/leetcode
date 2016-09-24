package main

import (
	"errors"
	"fmt"
)

var (
	noChildrenErr = errors.New("no children")
)

type MaxHeap struct {
	val []int
}

func (mh *MaxHeap) leftIndex(i int) int {
	return i*2 + 1
}

func (mh *MaxHeap) rightIndex(i int) int {
	return i*2 + 2
}

func (mh *MaxHeap) parentIndex(i int) int {
	return (i - 1) / 2
}

func (mh *MaxHeap) swap(a, b int) {
	t := mh.val[a]
	mh.val[a] = mh.val[b]
	mh.val[b] = t
}

func (mh *MaxHeap) maxChildIndex(r int) (int, error) {
	if mh.leftIndex(r) < len(mh.val) && mh.rightIndex(r) < len(mh.val) {
		if mh.val[mh.leftIndex(r)] > mh.val[mh.rightIndex(r)] {
			return mh.leftIndex(r), nil
		}
		return mh.rightIndex(r), nil
	} else if mh.leftIndex(r) < len(mh.val) {
		return mh.leftIndex(r), nil
	} else if mh.rightIndex(r) < len(mh.val) {
		return mh.rightIndex(r), nil
	}
	return -1, noChildrenErr
}

func (mh *MaxHeap) Insert(v int) {
	mh.val = append(mh.val, v)
	p := len(mh.val) - 1
	for mh.val[mh.parentIndex(p)] < v {
		mh.swap(mh.parentIndex(p), p)
		p = mh.parentIndex(p)
	}
}

func (mh *MaxHeap) Extract() int {
	ret := mh.val[0]
	mh.val[0] = mh.val[len(mh.val)-1]
	mh.val = mh.val[:len(mh.val)-1]

	r := 0
	for {
		// select child max
		maxChild, err := mh.maxChildIndex(r)
		if err == noChildrenErr {
			break
		}
		if mh.val[r] < mh.val[maxChild] {
			mh.swap(r, maxChild)
			r = maxChild
		} else {
			break
		}
	}
	return ret
}

func NewMaxHeap(val []int) *MaxHeap {
	mh := &MaxHeap{}
	for _, v := range val {
		mh.Insert(v)
	}
	return mh
}

func findKthLargest(nums []int, k int) int {
	mh := NewMaxHeap(nums)
	r := 0
	for i := 0; i < k; i++ {
		r = mh.Extract()
	}
	return r
}

func main() {
	n := []int{3, 2, 1, 5, 6, 4}
	fmt.Println(findKthLargest(n, 2))
}
