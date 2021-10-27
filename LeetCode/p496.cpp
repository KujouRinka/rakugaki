// 栈保证第一个
// 递减保证第一个
class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> check_map;
        stack<int> incr_stack;

        for (auto rit = nums2.rbegin(); rit != nums2.rend(); ++rit) {
            while (true) {
                if (incr_stack.empty()) {
                    check_map[*rit] = -1;
                    incr_stack.push(*rit);
                    break;
                }
                if (incr_stack.top() < *rit) {
                    incr_stack.pop();
                } else {
                    check_map[*rit] = incr_stack.top();
                    incr_stack.push(*rit);
                    break;
                }
            }
        }

        vector<int> result;
        result.reserve(nums1.size());
        for (int i: nums1)
            result.push_back(check_map[i]);
        return result;
    }
};
