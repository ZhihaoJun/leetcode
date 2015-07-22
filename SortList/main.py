# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    @staticmethod
    def createList(s):
        """
            s='3,4,2,1,23,4,6'
        """
        values = s.split(',')
        head = ListNode(0)
        current = head
        for v in values:
            current.next = ListNode(v)
            current = current.next
        return head.next

    @staticmethod
    def printList(head):
        current = head
        while current is not None:
            print(current.val)
            current = current.next


class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def sortList(self, head):
        pass


def main():
    head = ListNode.createList('1,2,3,4')
    ListNode.printList(head)

if __name__ == '__main__':
    main()
