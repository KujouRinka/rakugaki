/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* partition(struct ListNode* head, int x){
    if (head == NULL)
        return NULL;
    struct ListNode *nh = (struct ListNode *) malloc(16);
    nh->next = head;
    head = nh;

    struct ListNode *parted = NULL;
    struct ListNode *parted_tail = NULL;
    struct ListNode *previous = head;
    struct ListNode *current = head->next;
    while (current != NULL) {
        if (current->val < x) {
            if (parted_tail == NULL)
                parted = current;
            else
                parted_tail->next = current;
            parted_tail = current;

            previous->next = parted_tail->next;
        } else {
            previous = previous->next;
        }
        current = current->next;
    }
    if (parted != NULL) {
        parted_tail->next = head->next;
        head->next = parted;
    }

    // should free head
    return head->next;
}

