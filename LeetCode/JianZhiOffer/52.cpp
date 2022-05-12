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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lA = len(headA), lB = len(headB);
        int go = abs(lA - lB);
        ListNode *&goer = lA < lB ? headB : headA;
        while (go--)
            goer = goer->next;
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }

private:
    int len(ListNode *head) {
        int l = 0;
        while (head != nullptr) {
            head = head->next;
            ++l;
        }
        return l;
    }
};

