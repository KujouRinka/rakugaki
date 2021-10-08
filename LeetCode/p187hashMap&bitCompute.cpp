class Solution {
private:
    static unordered_map<char, uint32_t> char_to_bin;
    static unordered_map<uint32_t, char> bin_to_char;
    inline static string binToStr(uint32_t bin_var) {
        string s(10, ' ');
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            *it = bin_to_char[(bin_var & 0x03)];
            bin_var >>= 2;
        }
        return s;
    }
public:
    vector<string> findRepeatedDnaSequences(const string &s) {
        if (s.size() < 10)
            return {};
        vector<string> result;
        unordered_map<uint32_t, int> cnt_map;
        uint32_t tmp_str_bin = 0;
        uint32_t mask = 0xfffff;
        for (int i = 0; i < 9; ++i) {
            tmp_str_bin <<= 2;
            tmp_str_bin |= char_to_bin[s[i]];
        }
        for (char ch: s.substr(9)) {
            tmp_str_bin <<= 2;
            tmp_str_bin |= char_to_bin[ch];
            tmp_str_bin &= mask;
            if (++cnt_map[tmp_str_bin] == 2)
                result.push_back(binToStr(tmp_str_bin));
        }
        return result;
    }
};

unordered_map<char, uint32_t> Solution::char_to_bin = {
        {'A', 0x00},
        {'G', 0x01},
        {'C', 0x02},
        {'T', 0x03},
};

unordered_map<uint32_t, char> Solution::bin_to_char = {
        {0x00, 'A'},
        {0x01, 'G'},
        {0x02, 'C'},
        {0x03, 'T'},
};
