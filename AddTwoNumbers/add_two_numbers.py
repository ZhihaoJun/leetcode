# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        n1 = l1
        n2 = l2
        ret = ListNode(0)
        retp = ret
        carry = 0
        while n1 is not None and n2 is not None:
            n = n1.val + n2.val + carry
            carry = 0
            if n >= 10:
                carry = n/10
                n %= 10
            retp.next = ListNode(0)
            retp = retp.next
            retp.val = n
            # print(n, carry)
            n1 = n1.next
            n2 = n2.next

        while n1 is not None:
            n = n1.val + carry
            carry = 0
            if n >= 10:
                carry = n/10
                n %= 10
            # print(n, carry)
            retp.next = ListNode(0)
            retp = retp.next
            retp.val = n
            n1 = n1.next

        while n2 is not None:
            n = n2.val + carry
            carry = 0
            if n >= 10:
                carry = n/10
                n %= 10
            # print(n, carry)
            retp.next = ListNode(0)
            retp = retp.next
            retp.val = n
            n2 = n2.next

        if carry != 0:
            retp.next = ListNode(carry)

        return ret.next


def printNumber(l):
    n = l
    while n is not None:
        print(n.val)
        n = n.next

l1 = ListNode(5)
l2 = ListNode(5)

k = Solution().addTwoNumbers(l1, l2)
printNumber(k)
