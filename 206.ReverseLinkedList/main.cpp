#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *n) {
    while (n != NULL) {
        cout << n->val << " " << endl;
        n = n->next;
    }
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (NULL == head) {
            return NULL;
        }
        if (NULL == head->next) {
            return head;
        }
        ListNode *last = NULL;
        ListNode *current = head;
        ListNode *next = current->next;

        do {
            next = current->next;
            current->next = last;
            last = current;
            current = next;
        } while (current != NULL);

        return last;
    }
};

int main() {
    Solution s;

    ListNode *head = new ListNode(1);
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(3);
    ListNode *n3 = new ListNode(4);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;

    print(head);
    print(s.reverseList(head));
    return 0;
}
