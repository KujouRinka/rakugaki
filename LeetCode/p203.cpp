class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *virtual_head = new ListNode(-1, head);
        head = virtual_head;
        ListNode *previous = head, *current = head->next;
        while (current != nullptr) {
            if (current->val == val) {
                ListNode *tmp = current->next;
                delete current;
                current = tmp;
                previous->next = current;
            } else {
                previous = current;
                current = current->next;
            }
        }
        return head->next;
    }
};

