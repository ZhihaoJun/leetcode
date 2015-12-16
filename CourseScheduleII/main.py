class Node(object):
    def __init__(self, x):
        super(Node, self).__init__()
        self.val = x
        self.outedge = []
        self.inedge = []
        self.ins = 0
        self.outs = 0

    def add_out(self, n):
        self.outedge.append(n)
        self.outs += 1

    def add_in(self, n):
        self.inedge.append(n)
        self.ins += 1


class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        nodes = {}
        for i in xrange(numCourses):
            nodes[i] = Node(i)

        for edge in prerequisites:
            nodes[edge[1]].add_out(nodes[edge[0]])
            nodes[edge[0]].add_in(nodes[edge[1]])

        # topological sort


def dfs_print(root):
    visited = []

    def _dfs_print(root):
        visited.append(root.val)
        print(root.val)
        for n in root.outedge:
            if n.val not in visited:
                _dfs_print(n)

    _dfs_print(root)


def main():
    Solution().findOrder(4, [[1, 0], [2, 0], [3, 1], [3, 2]])

if __name__ == "__main__":
    main()
