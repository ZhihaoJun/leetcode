# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    @staticmethod
    def from_list(l):
        head = ListNode(0)
        cur = head
        for i in l:
            cur.next = ListNode(i)
            cur = cur.next
        return head.next

    def to_list(self):
        cur = self
        ret = []
        while cur is not None:
            ret.append(cur.val)
            cur = cur.next

        return ret


class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        before = None
        cur = head
        ret_head = ListNode(0)
        ret_cur = ret_head
        while cur is not None:
            if cur.val < x:
                # pop out
                if before is not None:
                    before.next = cur.next
                cur.next = None
                ret_cur.next = cur
                ret_cur = ret_cur.next
            before = cur
            cur = cur.next


def main():
    l = ListNode.from_list([1, 2, 3, 4])
    print(l.to_list())


if __name__ == '__main__':
    main()
