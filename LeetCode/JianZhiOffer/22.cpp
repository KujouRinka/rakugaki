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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        auto nn = new ListNode(0);
        nn->next = head;
        auto back = nn;
        for (int i = 0; back != nullptr && i < k; ++i)
            back = back->next;
        auto front = nn;
        while (back != nullptr) {
            front = front->next;
            back = back->next;
        }
        delete nn;
        return front == nn ? nullptr : front;
    }
};

