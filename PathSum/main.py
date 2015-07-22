# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    # @param {TreeNode} root
    # @param {integer} sum
    # @return {boolean}
    def hasPathSum(self, root, sum):
        if root is None:
            return False
        # reduce sum
        sum -= root.val
        # current node must be a leaf
        if sum == 0 and root.left is None and root.right is None:
            return True
        if self.hasPathSum(root.left, sum) or self.hasPathSum(root.right, sum):
            return True
        return False


def main():
    root = TreeNode(-5)
    root.left = TreeNode(4)
    root.right = TreeNode(8)
    root.left.left = TreeNode(11)
    root.left.left.left = TreeNode(7)
    root.left.left.right = TreeNode(2)
    root.right.left = TreeNode(13)
    root.right.right = TreeNode(4)
    root.right.right.right = TreeNode(1)
    # root = TreeNode(1)
    # root.left = TreeNode(2)
    print(Solution().hasPathSum(root, 16))

if __name__ == '__main__':
    main()
