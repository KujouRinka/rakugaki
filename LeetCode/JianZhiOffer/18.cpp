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
    ListNode* deleteNode(ListNode* head, int val) {
        auto nh = head;
        if (head == nullptr)
            return nullptr;
        if (head->val == val)
            return head->next;
        while (head->next != nullptr && head->next->val != val)
            head = head->next;
        if (head->next != nullptr)
            head->next = head->next->next;
        return nh;
    }
};

