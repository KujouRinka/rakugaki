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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        auto *head = new ListNode(-1);
        ListNode *now = head;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val <= p2->val) {
                now->next = p1;
                p1 = p1->next;
            } else {
                now->next = p2;
                p2 = p2->next;
            }
            now = now->next;
        }

        if (p1 != nullptr)
            now->next = p1;
        if (p2 != nullptr)
            now->next = p2;

        ListNode *tp = head->next;
        delete head;
        return tp;
    }
};
