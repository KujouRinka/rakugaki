class Solution {
public:
    string optimalDivision(const vector<int>& nums) {
        auto sz = nums.size();
        string result;
        result.reserve(sz * 2);
        for (int i = 0; i < sz; ++i) {
            if (i != 0)
                result.push_back('/');
            if (i == 1 && sz != 2)
                result.push_back('(');
            result.append(to_string(nums[i]));
        }
        if (sz > 2)
            result.push_back(')');
        return result;
    }
};

