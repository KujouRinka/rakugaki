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
  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    auto *entry = head;
    while (entry != nullptr && entry->next != nullptr) {
      int g = gcd(entry->val, entry->next->val);
      auto *to_insert = new ListNode(g, entry->next);
      entry->next = to_insert;
      entry = to_insert->next;
    }
    return head;
  }
};

