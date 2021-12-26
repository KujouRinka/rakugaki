class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *virtual_head = new ListNode(-1, head);
        head = virtual_head;
        ListNode *fast = head, *slow = head;
        ++n;
        while (n-- && fast != nullptr)
            fast = fast->next;
        if (n > 0)
            return head;
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        if (slow != nullptr) {
            ListNode *tmp = slow->next->next;
            delete slow->next;
            slow->next = tmp;
        }
        return head->next;
    }
};

