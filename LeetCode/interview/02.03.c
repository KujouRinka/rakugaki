/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    // should free node->next in practice
    node->next = node->next->next;
}

