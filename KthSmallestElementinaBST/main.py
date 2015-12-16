# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.k = k
        self.result = root.val
        self.running = True
        self.visit(root)
        return self.result

    def visit(self, root):
        if root is None or not self.running:
            return
        self.visit(root.left)
        self.k -= 1
        if self.k == 0:
            self.result = root.val
            self.running = False
        self.visit(root.right)


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

    root = TreeNode(10)

    print(Solution().kthSmallest(root, 2))

if __name__ == "__main__":
    main()
