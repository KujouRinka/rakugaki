/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *previous = nullptr;
        ListNode *ths = head;
        ListNode *next = nullptr;
        for (ths = head; ths != nullptr; ) {
            next = ths->next;
            ths->next = previous;
            previous = ths;
            ths = next;
        }
        
        return previous;
    }
};
