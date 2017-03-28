/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *head) {
    ListNode *n = head;
    while (n != NULL) {
        cout << n->val << " ";
        n = n->next;
    }
}

ListNode *makeListNode(vector<int> &vec) {
    ListNode *head = new ListNode(vec[0]);
    ListNode *n = head;
    for (int i=1; i<vec.size(); i++) {
        n->next = new ListNode(vec[i]);
        n = n->next;
    }
    return head;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> heads(lists.size());
        int count = 0;
        int i, minIdx;
        ListNode *tail = new ListNode(0);
        ListNode *beforeHead = tail;

        for (int i=0; i<lists.size(); i++) {
            heads[i] = lists[i];
        }

        while (1) {
            // select the min head
            minIdx = -1;
            count = 0;
            for (i=0; i<heads.size(); i++) {
                // is end?
                if (NULL == heads[i]) {
                    count ++;
                    continue;
                }
                if (-1 == minIdx) {
                    minIdx = i;
                } else if (heads[i]->val < heads[minIdx]->val) {
                    minIdx = i;
                }
            }

            // all ends?
            if (count == heads.size()) {
                break;
            }

            // connect
            tail->next = heads[minIdx];
            tail = tail->next;
            heads[minIdx] = heads[minIdx]->next;
        }
        return beforeHead->next;
    }
};

int main() {
    Solution s;

    vector<int> v{1, 3, 20};
    vector<int> v1{5, 6};
    vector<int> v2{9, 10};
    ListNode *l1 = makeListNode(v);
    ListNode *l2 = makeListNode(v1);
    ListNode *l3 = makeListNode(v2);
    vector<ListNode *> lists = {l1, l2, l3};

    ListNode *head = s.mergeKLists(lists);
    print(head);
    return 0;
}
