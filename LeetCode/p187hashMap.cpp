constexpr int STR_LEN = 10;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(const string &s) {
        unordered_map<string, int> cnt_map;
        vector<string> result;
        int sz = s.size();      // don't use auto, for preventing uint from overflowing.
        for (int i = 0; i <= sz - STR_LEN; ++i) {
            string tmp_str = s.substr(i, STR_LEN);
            if (++cnt_map[tmp_str] == 2)
                result.push_back(tmp_str);
        }
        return result;
    }
};
