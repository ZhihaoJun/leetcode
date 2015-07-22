# Definition for a undirected graph node
class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []

    @staticmethod
    def unserialize(s):


class Solution:
    # @param nodes dictionary to save label-node
    # @param node node to be copied
    # @return a copied node of node
    def _cloneGraph(self, node, nodes):
        if node is None:
            return None
        if node.label not in nodes:
            nodes[node.label] = UndirectedGraphNode(node.label)
        n = nodes[node.label]
        for neighbor in node.neighbors:
            if neighbor.label not in nodes:
                nodes[neighbor.label] = self._cloneGraph(neighbor, nodes)
            n.neighbors.append(nodes[neighbor.label])
        return n

    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        nodes = {}
        return self._cloneGraph(node, nodes)

    def _DFS(self, node, visited, nodes):
        if node is None or node.label in visited:
            return
        nodes[node.label] = node
        visited.append(node.label)
        for n in node.neighbors:
            self._DFS(n, visited, nodes)

    def DFS(self, node):
        if node is None:
            return {}
        visited = []
        nodes = {}
        self._DFS(node, visited, nodes)
        return nodes

    def toSerial(self, nodes):
        parts = []
        for label, n in nodes.iteritems():
            nei_labels = [nei.label for nei in n.neighbors]
            nei_labels.insert(0, label)
            part = ','.join(nei_labels)
            parts.append(part)
        return '#'.join(parts)


def main():
    node = UndirectedGraphNode.createGraph('0,1#1,2#2,2')
    node1 = Solution().cloneGraph(node)
    print Solution().toSerial(Solution().DFS(node))
    print Solution().toSerial(Solution().DFS(node1))

if __name__ == '__main__':
    main()
