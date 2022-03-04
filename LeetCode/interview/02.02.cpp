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
    int kthToLast(ListNode* head, int k) {
        auto fast = head;
        while (k--)
            fast = fast->next;
        auto slow = head;
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->val;
    }
};

