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
    Solution() : e(time(nullptr)) {
        val_vec.reserve(5e3);
    }

    Solution(ListNode *head) {
        while (head != nullptr) {
            val_vec.push_back(head->val);
            head = head->next;
        }
        d = uniform_int_distribution<int>(0, val_vec.size() - 1);
    }

    int getRandom() {
        return val_vec[d(e)];
    }

private:
    default_random_engine e;
    uniform_int_distribution<int> d;
    vector<int> val_vec;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

