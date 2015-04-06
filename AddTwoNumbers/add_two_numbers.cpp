#include <iostream>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;
 
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* ret = new ListNode(0);
        ListNode* ret_p = ret;
        ListNode* l1_p = l1;
        ListNode* l2_p = l2;
        int carry = 0;

        while (l1_p != NULL) {
            // add l1
            ret_p->next = new ListNode(l1_p->val);
            ret_p = ret_p->next;

            // add l2
            if (l2_p != NULL) {
                ret_p->val += l2_p->val;
                l2_p = l2_p->next;
            }

            // handle carry
            if (carry != 0) {
                ret_p->val += carry;
                carry = 0;
            }

            // mod current and calculate carry
            if (ret_p->val >= 10) {
                carry = ret_p->val / 10;
                ret_p->val %= 10;
            }
            l1_p = l1_p->next;
        }

        while (l2_p != NULL) {
            ret_p->next = new ListNode(l2_p->val);
            ret_p = ret_p->next;

            if (carry != 0) {
                ret_p->val += carry;
                carry = 0;
            }

            if (ret_p->val >= 10) {
                carry = ret_p->val / 10;
                ret_p->val %= 10;
            }
            l2_p = l2_p->next;
        }

        if (carry != 0) {
            ret_p->next = new ListNode(carry);
        }

        return ret->next;
    }
};

void printNumber(ListNode* n)
{
    ListNode* p = n;
    while (p != NULL) {
        cout << p->val;
        p = p->next;
    }
    cout << "\n";
}

int main(void) {
    // ListNode* n1 = new ListNode(2);
    // n1->next = new ListNode(4);
    // n1->next->next = new ListNode(3);
    // n1->next->next->next = new ListNode(9);

    // ListNode* n2 = new ListNode(5);
    // n2->next = new ListNode(6);
    // n2->next->next = new ListNode(8);
    // n2->next->next->next = new ListNode(4);
    ListNode* n1 = new ListNode(0);
    ListNode* n2 = new ListNode(0);
    Solution s = Solution();
    ListNode* ret = s.addTwoNumbers(n1, n2);

    printNumber(ret);

    return 0;
}