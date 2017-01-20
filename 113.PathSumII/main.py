# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def inorder(self, root, sum):
        if root is None:
            return
        self.stack.append(root.val)
        self.inorder(root.left, sum + root.val)
        if root.left is None and root.right is None:
            if sum + root.val == self.aim:
                self.paths.append(self.stack[:])
        self.inorder(root.right, sum + root.val)
        self.stack.pop()

    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        self.paths = []
        self.stack = []
        self.aim = sum
        self.inorder(root, 0)
        return self.paths

def main():
    root = TreeNode(5)
    n1 = TreeNode(4)
    n2 = TreeNode(8)
    n3 = TreeNode(11)
    n4 = TreeNode(13)
    n5 = TreeNode(4)
    n6 = TreeNode(7)
    n7 = TreeNode(2)
    n8 = TreeNode(5)
    n9 = TreeNode(1)

    # root.left = n1
    # root.right = n2

    n1.left = n3

    n2.left = n4
    n2.right = n5

    n3.left = n6
    n3.right = n7

    n5.left = n8
    n5.right = n9

    s = Solution()

    print s.pathSum(root, 5)

if __name__ == '__main__':
    main()
