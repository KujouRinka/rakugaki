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
    ListNode *mergeNodes(ListNode *head) {
        ListNode *prev_zero = head;
        ListNode *previous = head;
        ListNode* current = head->next;
        if (current == nullptr)
            return nullptr;
        while (current != nullptr) {
            int s = 0;
            while (current->val != 0) {
                s += current->val;
                previous = current;
                current = current->next;
            }
            previous->val = s;
            prev_zero->next = previous;
            prev_zero = current;
            previous = current;
            current = current->next;
        }
        ListNode *h = head->next;
        while (h != nullptr) {
            h->next = h->next->next;
            h = h->next;
        }
        return head->next;
    }
};

