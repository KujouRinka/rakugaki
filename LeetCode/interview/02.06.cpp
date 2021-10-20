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
    bool isPalindrome(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *previous = nullptr;
        while (slow != nullptr) {
            ListNode *next = slow->next;
            slow->next = previous;
            previous = slow;
            slow = next;
        }
        while (previous != nullptr) {
            if (head->val != previous->val)
                return false;
            head = head->next;
            previous = previous->next;
        }
        return true;
    }
}
