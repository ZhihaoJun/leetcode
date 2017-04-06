#include <iostream>
#include <vector>

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

void printList(ListNode *head) {
  ListNode *n = head;
  while (n != NULL) {
    cout << n->val << " ";
    n = n->next;
  }
}

ListNode *makeListNode(vector<int> &vec) {
  ListNode *fakeHead = new ListNode(0);
  ListNode *n = fakeHead;
  for (auto i : vec) {
    n->next = new ListNode(i);
    n = n->next;
  }
  return fakeHead->next;
}

class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode *fakeHead = new ListNode(0);
    fakeHead->next = head;
    ListNode *n = head;
    ListNode *prev = fakeHead;

    while (n != NULL) {
      if (n->val == val) {
        // remove n
        prev->next = n->next;
      } else {
        prev = n;
      }
      n = n->next;
    }
    return fakeHead->next;
  }
};

int main() {
  Solution s;
  vector<int> vec{1, 1};
  ListNode *head = makeListNode(vec);
  printList(head);
  cout << endl;
  ListNode *res = s.removeElements(head, 1);
  printList(res);
  return 0;
}
