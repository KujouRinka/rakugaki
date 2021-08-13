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
    vector<int> tmp;
    vector<int> reversePrint(ListNode* head) {
        for (auto now = head; now != nullptr; now = now->next)
            tmp.push_back(now->val);
        return vector<int>(tmp.crbegin(), tmp.crend());
    }
};
