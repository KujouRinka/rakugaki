class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> tail;
        for (int i : nums) {
            auto it = lower_bound(tail.begin(), tail.end(), i);
            if (it == tail.end())
                tail.push_back(i);
            else if (i < *it)
                *it = i;
        }
        return tail.size();
    }
};
