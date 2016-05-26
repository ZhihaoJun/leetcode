package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}

	fakeHead := &ListNode{
		Next: head,
	}
	last := fakeHead
	prev := head
	current := head.Next

	for current != nil {
		if prev.Val == current.Val {
			last.Next = current.Next
		} else if current != last.Next {
			last = prev
		}

		prev = current
		current = current.Next
	}

	return fakeHead.Next
}

func print(head *ListNode) {
	current := head
	for current != nil {
		fmt.Println(current.Val)
		current = current.Next
	}
}

func main() {
	head := &ListNode{
		Val: 1,
	}
	n1 := &ListNode{
		Val: 1,
	}
	n2 := &ListNode{
		Val: 2,
	}
	n3 := &ListNode{
		Val: 2,
	}
	n4 := &ListNode{
		Val: 3,
	}
	n5 := &ListNode{
		Val: 4,
	}
	n6 := &ListNode{
		Val: 5,
	}
	head.Next = n1
	n1.Next = n2
	n2.Next = n3
	n3.Next = n4
	n4.Next = n5
	n5.Next = n6
	print(head)
	fmt.Println("---------")
	ret := deleteDuplicates(head)
	print(ret)
}
