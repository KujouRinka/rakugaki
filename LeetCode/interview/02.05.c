/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0;
    struct ListNode *l1h = (struct ListNode *) malloc(sizeof(struct ListNode));
    l1h->next = l1;

    struct ListNode *l1p = l1h;
    while (l1 != NULL && l2 != NULL) {
        int t = l1->val + l2->val + carry;
        l1->val = t % 10;
        carry = t / 10;
        l1 = l1->next;
        l2 = l2->next;
        l1p = l1p->next;
    }
    if (l1 == NULL)
        l1 = l1p->next = l2;
    while (carry == 1) {
        if (l1 == NULL) {
            l1 = l1p->next = (struct ListNode *) malloc(sizeof(struct ListNode));
            l1->val = 0;
            l1->next = NULL;
        }
        int t = l1->val + 1;
        l1->val = t % 10;
        carry = t / 10;
        l1p = l1;
        l1 = l1->next;
    }
    
    // should free head
    return l1h->next;
}

