/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class defer {
public:
    defer(function<void()> f) : _f(f) {}
    ~defer() { _f(); }

private:
    function<void()> _f;
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        auto l1cp = l1, l2cp = l2;
        auto fake = new ListNode(0);
        auto fake_cp = fake;
        while (l1cp && l2cp) {
            if (l1cp->val < l2cp->val) {
                fake_cp->next = l1cp;
                l1cp = l1cp->next;
            } else {
                fake_cp->next = l2cp;
                l2cp = l2cp->next;
            }
            fake_cp = fake_cp->next;
        }
        fake_cp->next = l1cp ? l1cp : l2cp;
        defer d([fake]() { delete fake; });
        return fake->next;
    }
};

