class Solution {
public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
        multimap<int, int> map;
        for (auto &n: nums) {
            string s = to_string(n);
            for (char &c: s)c = mapping[c - '0'] + '0';
            map.insert({stoi(s), n});
        }
        int i = 0;
        for (auto &m: map) {
            nums[i] = m.second;
            ++i;
        }
        return nums;
    }
};

