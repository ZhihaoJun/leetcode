package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func midorder(root *TreeNode) []int {
	if root == nil {
		return nil
	}
	left := midorder(root.Left)
	right := midorder(root.Right)
	result := append(left, root.Val)
	result = append(result, right...)
	return result
}

func preorder(root *TreeNode) []int {
	if root == nil {
		return nil
	}
	left := preorder(root.Left)
	right := preorder(root.Right)
	result := append([]int{root.Val}, left...)
	result = append(result, right...)
	return result
}

func postorder(root *TreeNode) []int {
	if root == nil {
		return nil
	}
	left := postorder(root.Left)
	right := postorder(root.Right)
	result := append(left, right...)
	result = append(result, root.Val)
	return result
}

func isSymmetricInts(l []int) bool {
	llen := len(l)
	for i := 0; i < llen/2; i++ {
		if l[i] != l[llen-i-1] {
			return false
		}
	}
	return true
}

func reverseSame(a, b []int) bool {
	llen := len(a)
	for i, n := range a {
		if b[llen-i-1] != n {
			return false
		}
	}
	return true
}

func isSymmetric(root *TreeNode) bool {
	mid := midorder(root)
	pre := preorder(root)
	post := postorder(root)
	return isSymmetricInts(mid) && reverseSame(pre, post)
}

func main() {
	// root := &TreeNode{
	// 	Val: 1,
	// }
	// n1 := &TreeNode{
	// 	Val: 2,
	// }
	// n2 := &TreeNode{
	// 	Val: 2,
	// }
	// n3 := &TreeNode{
	// 	Val: 3,
	// }
	// n4 := &TreeNode{
	// 	Val: 4,
	// }
	// n5 := &TreeNode{
	// 	Val: 3,
	// }
	// n6 := &TreeNode{
	// 	Val: 4,
	// }
	// root.Left = n1
	// root.Right = n2
	// n1.Left = n3
	// n1.Right = n4
	// n2.Left = n6
	// n2.Right = n5

	root := &TreeNode{
		Val: 1,
	}
	n1 := &TreeNode{
		Val: 2,
	}
	n2 := &TreeNode{
		Val: 3,
	}
	n3 := &TreeNode{
		Val: 3,
	}
	n4 := &TreeNode{
		Val: 2,
	}
	root.Left = n1
	root.Right = n2
	n1.Left = n3
	n2.Right = n4
	fmt.Println(isSymmetric(root))
}
