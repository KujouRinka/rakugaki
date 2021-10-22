class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> count;
        vector<int> result;
        for (int i: nums)
            ++count[i];
        auto sz = nums.size() / 3;
        for (auto &p: count) {
            if (p.second > sz)
                result.push_back(p.first);
        }
        return result;
    }
};
