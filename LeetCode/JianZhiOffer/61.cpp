class Solution {
public:
    bool isStraight(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        auto it = find_if(nums.begin(), nums.end(), [](auto i) { return i != 0; });
        auto rep = it - nums.begin();
        if (it++ == nums.end())
            return true;
        for (; it != nums.end(); ++it) {
            int m = *it - *prev(it) - 1;
            if (m < 0)
                return false;
            rep -= m;
            if (rep < 0)
                return false;
        }
        return true;
    }
};

