class Solution {
public:
    string minNumber(vector<int> &nums) {
        vector<string> v;
        for_each(nums.begin(), nums.end(), [&v](auto i) { v.push_back(to_string(i)); });
        auto f = [](string &l, string &r) -> bool {
            return l + r < r + l;
        };
        sort(v.begin(), v.end(), f);
        string result;
        for_each(v.begin(), v.end(), [&result](auto &s) { result.append(s); });
        return result;
    }
};

