class Solution {
public:
    vector<int> replaceNonCoprimes(const vector<int> &nums) {
        vector<int> tv;
        tv.push_back(nums[0]);
        auto sz = nums.size();
        for (int i = 1; i < sz; ++i) {
            int prev = tv.back();
            int cur = nums[i];
            while (gcd(prev, cur) != 1) {
                cur = lcm(cur, prev);
                tv.pop_back();
                if (tv.empty())
                    break;
                prev = tv.back();
            }
            tv.push_back(cur);
        }
        return tv;
    }
};

