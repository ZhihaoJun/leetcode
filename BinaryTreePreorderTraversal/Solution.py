# Given a binary tree, return the preorder traversal of its nodes' values.

# For example:
# Given binary tree {1,#,2,3},
#    1
#     \
#      2
#     /
#    3
# return [1,2,3].

# Note: Recursive solution is trivial, could you do it iteratively?


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class PreorderIterator(object):
    def __init__(self, root):
        self.stack = []
        if root is not None:
            self.stack.append(root)

    def hasNext(self):
        return len(self.stack) != 0

    def next(self):
        ret = self.stack.pop()
        if ret.right is not None:
            self.stack.append(ret.right)
        if ret.left is not None:
            self.stack.append(ret.left)
        return ret.val


class Solution:
    # @param {TreeNode} root
    # @return {integer[]}
    def preorderTraversal(self, root):
        i, v = PreorderIterator(root), []
        while i.hasNext():
            v.append(i.next())
        return v

    def recursivePreorder(self, root):
        if root is None:
            return
        print root.val
        self.recursivePreorder(root.left)
        self.recursivePreorder(root.right)

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.right.left = TreeNode(4)
root.right.right = TreeNode(5)

print Solution().preorderTraversal(root)
Solution().recursivePreorder(root)

