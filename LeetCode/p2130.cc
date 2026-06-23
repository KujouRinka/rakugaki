class Solution {
public:
  int pairSum(ListNode *head) {
    ListNode *f = head;
    ListNode *b = head->next;
    while (b->next) {
      f = f->next;
      b = b->next->next;
    }
    b = f->next;
    f->next = nullptr;
    ListNode *tp = nullptr;
    while (b) {
      ListNode *n = b->next;
      b->next = tp;
      tp = b;
      b = n;
    }
    int ret = 0;
    while (head) {
      ret = max(ret, head->val + tp->val);
      head = head->next;
      tp = tp->next;
    }
    return ret;
  }
};

