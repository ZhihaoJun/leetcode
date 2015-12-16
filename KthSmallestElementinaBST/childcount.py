# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def childCount(self, root):
        if root is None:
            return 0
        if root.val in self.childs:
            return self.childs[root.val]
        return 1 + self.childCount(root.left) + self.childCount(root.right)

    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.childs = {}
        node = root
        while node is not None:
            count = self.childCount(node.left)
            print(node.val, count)
            if count + 1 == k:
                return node.val
            elif count + 1 > k:
                node = node.left
            else:
                k -= count + 1
                node = node.right
        return -1


def main():
    root = TreeNode(8)
    n1 = TreeNode(1)
    n3 = TreeNode(3)
    n4 = TreeNode(4)
    n6 = TreeNode(6)
    n7 = TreeNode(7)
    n10 = TreeNode(10)
    n13 = TreeNode(13)
    n14 = TreeNode(14)

    n14.left = n13
    n10.right = n14
    root.right = n10
    n6.left = n4
    n6.right = n7
    n3.left = n1
    n3.right = n6
    root.left = n3

    print(Solution().kthSmallest(root, 7))

if __name__ == "__main__":
    main()
