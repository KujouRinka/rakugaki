/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode *swapPairs(ListNode *head) {
    ListNode dummy;
    dummy.next = head;
    auto *pre = &dummy;
    auto *n1 = head;
    auto *n2 = head;
    while (n1 != nullptr && n1->next != nullptr) {
      n2 = n1->next;
      n1->next = n2->next;
      n2->next = n1;
      pre->next = n2;
      pre = n1;
      n1 = n1->next;
    }
    return dummy.next;
  }
};

