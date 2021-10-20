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
    ListNode *removeDuplicateNodes(ListNode *head) {
        unordered_set<int> num_set;
        ListNode *previous = head;
        ListNode *result = head;
        while (head != nullptr) {
            if (num_set.count(head->val)) {
                ListNode *tmp = head->next;
                delete head;
                previous->next = tmp;
                head = tmp;
            } else {
                num_set.insert(head->val);
                previous = head;
                head = head->next;
            }
        }
        return result;
    }
};
