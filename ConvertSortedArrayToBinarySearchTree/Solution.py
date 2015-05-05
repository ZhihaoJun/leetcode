# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

    @staticmethod
    def inorder(node):
        if node is None:
            return
        TreeNode.inorder(node.left)
        print(node.val)
        TreeNode.inorder(node.right)


class Solution:
    # @param {integer[]} nums
    # @return {TreeNode}
    def sortedArrayToBST(self, nums):
        return self.buildTree(nums, 0, len(nums)-1)

    def buildTree(self, nums, left, right):
        if left > right:
            return None
        mid = left + (right - left)/2
        left = self.buildTree(nums, left, mid-1)
        root = TreeNode(nums[mid])
        root.left = left
        root.right = self.buildTree(nums, mid+1, right)
        return root

root = Solution().sortedArrayToBST([3, 5, 8])
TreeNode.inorder(root)
