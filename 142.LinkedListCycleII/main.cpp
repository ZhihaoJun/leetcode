#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fake = new ListNode(0);
    fake->next = head;
    ListNode *fast = fake;
    ListNode *slow = fake;
    while (1) {
      slow = slow->next;
      fast = fast->next;
      if (fast) {
        fast = fast->next;
      }
      if (fast == NULL || slow == NULL) {
        // no loop
        return NULL;
      }
      if (fast == slow) {
        break;
      }
    }
    
    // find start
    ListNode *n1 = fake;
    ListNode *n2 = fast;
    while (n1 != n2) {
      n1 = n1->next;
      n2 = n2->next;
    }
    return n1;
  }
};

int main() {
  Solution s;
  ListNode *head = new ListNode(1);
  ListNode *n1 = new ListNode(2);
  ListNode *n2 = new ListNode(3);
  ListNode *n3 = new ListNode(4);
  ListNode *n4 = new ListNode(5);

  head->next = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n1;

  cout << s.detectCycle(head) << endl;

  return 0;
}
