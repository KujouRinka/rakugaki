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
  void reorderList(ListNode *head) {
    if (head == nullptr) {
      return;
    }
    auto *node = head;
    int len = 0;
    while (node != nullptr) {
      ++len;
      node = node->next;
    }

    int step = (len + 1) / 2;
    auto node2 = head;
    while (--step) {
      node2 = node2->next;
    }
    node = node2->next;
    node2->next = nullptr;

    // reverse
    node2 = nullptr;
    while (node != nullptr) {
      auto *next = node->next;
      node->next = node2;
      node2 = node;
      node = next;
    }
    
    node = head;
    while (node2 != nullptr) {
      auto *n2_next = node2->next;
      node2->next = node->next;
      node->next = node2;
      node = node2->next;
      node2 = n2_next;
    }
  }
};

