# Definition for a  binary tree node
# Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
# Calling next() will return the next smallest number in the BST.
# Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class BSTIterator:
    # @param root, a binary search tree's root node
    def __init__(self, root):
        self.__stack = []
        node = root
        while node is not None:
            self.__stack.append(node)
            node = node.left

    # @return a boolean, whether we have a next smallest number
    def hasNext(self):
        return len(self.__stack) != 0

    # @return an integer, the next smallest number
    def next(self):
        ret = self.__stack.pop()
        node = ret.right
        while node is not None:
            self.__stack.append(node)
            node = node.left
        return ret.val

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())

root = TreeNode(2)
root.left = TreeNode(1)
root.right = TreeNode(7)
root.right.left = TreeNode(4)
root.right.left.left = TreeNode(3)
root.right.left.right = TreeNode(6)
root.right.left.right.left = TreeNode(5)
root.right.right = TreeNode(8)

i, v = BSTIterator(root), []
while i.hasNext():
    v.append(i.next())

print v

