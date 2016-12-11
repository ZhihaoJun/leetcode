# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def _postorder(self, root):
        if root is None:
            return
        self._postorder(root.left)
        self._postorder(root.right)
        self.res.append(root.val)

    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.res = []
        self._postorder(root)
        return self.res

def main():
    root = TreeNode(1)
    n1 = TreeNode(2)
    n2 = TreeNode(3)
    root.right = n1
    n1.left = n2
    print Solution().postorderTraversal(root)

if __name__ == '__main__':
    main()
