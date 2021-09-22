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
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        vector<ListNode *> result;
        int listLen = 0;
        ListNode *headP = head;
        while (headP != nullptr) {
            ++listLen;
            headP = headP->next;
        }
        int basePart = listLen / k;
        int modPart = listLen % k;
        ListNode *pre = nullptr;
        for (int i = 0; i < k; ++i) {
            result.push_back(head);
            for (int j = 0; head != nullptr && j < basePart + (modPart <= 0 ? 0 : 1); ++j) {
                pre = head;
                head = head->next;
            }
            if (pre != nullptr)
                pre->next = nullptr;
            --modPart;
        }

        return result;
    }
};
