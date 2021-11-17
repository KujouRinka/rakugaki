class Solution {
public:
    int maxProduct(const vector<string> &words) {
        map<uint32_t, int> word_map;
        for (auto &s: words) {
            uint32_t string_bit = 0;
            for (char ch: s)
                string_bit |= (1 << chToInd(ch));
            if (s.size() > word_map[string_bit])
                word_map[string_bit] = s.size();
        }
        int max_val = 0;
        for (auto it = word_map.begin(); it != word_map.end(); ++it) {
            for (auto it2 = next(it); it2 != word_map.end(); ++it2) {
                if ((it->first & it2->first) == 0)
                    max_val = max(max_val, it->second * it2->second);
            }
        }
        return max_val;
    }

private:
    inline static uint32_t chToInd(char ch) {
        return ch - 'a';
    }
};
