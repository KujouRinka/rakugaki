class Solution {
public:
  ListNode *deleteMiddle(ListNode *head) {
    ListNode **node = &head;
    ListNode **fp_node = &head;
    while (*fp_node != nullptr && (*fp_node)->next != nullptr) {
      node = &(*node)->next;
      fp_node = &(*fp_node)->next->next;
    }
    auto next = (*node)->next;
    // delete *node;
    *node = next;
    return head;
  }
};

