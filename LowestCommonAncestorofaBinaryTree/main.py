# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class UnionFind(object):
    def __init__(self):
        super(UnionFind, self).__init__()
        self.parent = {}
        self.rank = {}

    def makeSet(self, o):
        self.parent[o] = o
        self.rank[o] = 1

    def union(self, set1, set2):
        parent = self.find(set1)

    def find(self, o):
        try:
            if o != self.parent[o]:
                self.parent[o] = self.find(self.parent[o])
            return self.parent[o]
        except ValueError:
            pass
        return None


class Solution:
    # @param {TreeNode} root
    # @param {TreeNode} p
    # @param {TreeNode} q
    # @return {TreeNode}
    def lowestCommonAncestor(self, root, p, q):



def main():
    root = TreeNode(3)
    root.left = TreeNode(5)
    root.right = TreeNode(1)
    root.left.left = TreeNode(6)
    root.left.right = TreeNode(2)
    root.left.right.left = TreeNode(7)
    root.left.right.right = TreeNode(4)
    root.right.left = TreeNode(0)
    root.right.right = TreeNode(8)
    print(Solution().lowestCommonAncestor(root, root.left.left, root.left.right.right))

if __name__ == '__main__':
    main()
