class Solution {
public:
    string repeatLimitedString(const string &s, int repeatLimit) {
        int char_map[26] = {0};
        for (char ch: s)
            ++char_map[toInt(ch)];
        string result;
        result.reserve(s.size());

        int idx;
        while ((idx = findNC(result, char_map, repeatLimit)) != -1) {
            result.push_back(toChar(idx));
            --char_map[idx];
        }
        return result;
    }

private:
    int m_start = 25;

    static inline int toInt(char ch) {
        return ch - 'a';
    }

    static inline char toChar(int i) {
        return i + 'a';
    }

    int findNC(const string &s, int *char_map, int limit) {
        if (s.empty()) {
            for (int i = 25; i >= 0; --i)
                if (char_map[i] != 0) {
                    m_l_cnt = 1;
                    return i;
                }
        }
        int r = findNRep(s);
        int s_idx = toInt(s.back());
        bool zero_f = true;
        for (int i = m_start; i >= 0; --i) {
            if (char_map[i] > 0) {
                zero_f = false;
                if (i > s_idx)
                    return i;
                else if (i == s_idx) {
                    if (r < limit)
                        return i;
                } else {
                    return i;
                }
            }
            if (zero_f)
                m_start = i - 1;
        }
        return -1;
    }

    int m_l_c = -1;
    int m_l_cnt = 0;
    int findNRep(const string &s) {
        auto sz = s.size();
        if (sz <= 1)
            return sz;
        if (s[sz - 1] == s[sz - 2]) {
            ++m_l_cnt;
            return m_l_cnt;
        }
        m_l_cnt = 1;
        return 1;
    }
};

