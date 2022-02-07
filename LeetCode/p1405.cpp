class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string result;
        pair<int, char> pa = {a, 'a'}, pb = {b, 'b'}, pc = {c, 'c'};
        auto next = [&]() -> int {
            auto [max_p, max_s] = max3(pa, pb, pc);
            auto r_sz = result.size();
            if (r_sz < 2 || (result[r_sz - 1] != max_p.second || result[r_sz - 2] != max_p.second)) {
                if (max_p.first == 0) {
                    return -1;
                } else {
                    --max_p.first;
                    return max_p.second;
                }
            }
            if (max_s.first == 0)
                return -1;
            --max_s.first;
            return max_s.second;
        };
        int ch;
        while ((ch = next()) != -1)
            result.push_back(ch);
        return result;
    }

private:
    static inline pair<pair<int, char> &, pair<int, char> &> max3(
            pair<int, char> &pa, pair<int, char> &pb, pair<int, char> &pc
    ) {
        auto &m1 = max(pa, max(pb, pc));
        auto &t1 = max(pb, pc);
        if (max(t1, pa) == pa)
            return {const_cast<pair<int, char> &>(m1), const_cast<pair<int, char> &>(t1)};
        else
            return {const_cast<pair<int, char> &>(m1),
                    const_cast<pair<int, char> &>(max(min(pb, pc), pa))};
    }
};

