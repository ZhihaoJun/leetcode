# Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


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
    # @param {ListNode} head
    # @return {TreeNode}
    def sortedListToBST(self, head):
        self.data = []
        node = head
        while node is not None:
            self.data.append(node.val)
            node = node.next
        return self.buildTree(0, len(self.data)-1)

    def buildTree(self, left, right):
        if left > right:
            return None
        mid = (left + right)/2
        left = self.buildTree(left, mid-1)
        root = TreeNode(self.data[mid])
        root.left = left
        root.right = self.buildTree(mid+1, right)
        return root


def listToLinkedList(l):
    head = ListNode(l[0])
    n = head
    for item in l[1:]:
        n.next = ListNode(item)
        n = n.next
    return head


def printLinkList(head):
    n = head
    while n is not None:
        print(n.val)
        n = n.next

root = Solution().sortedListToBST(listToLinkedList([3, 5, 8]))
TreeNode.inorder(root)
