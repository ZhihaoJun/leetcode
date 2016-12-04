#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int listLen(ListNode *n) {
        int len = 0;
        while (n != NULL) {
            n = n->next;
            len ++;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        int i = 0;
        int lenA = listLen(headA);
        int lenB = listLen(headB);
        // to the same length start
        if (lenA > lenB) {
            for (i=0; i<lenA-lenB; i++) {
                a = a->next;
            }
        } else if (lenB > lenA) {
            for (i=0; i<lenB-lenA; i++) {
                b = b->next;
            }
        }

        // move together
        // no need for NULL check
        while (a != b) {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};

int main() {
    Solution s;
    ListNode *root = new ListNode(0);
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    ListNode *n6 = new ListNode(6);
    ListNode *n7 = new ListNode(7);
    ListNode *n8 = new ListNode(8);

    root->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    n5->next = n6;
    n6->next = n3;
    
    cout << n3 << endl;
    cout << s.getIntersectionNode(root, n5) << endl;

    return 0;
}
