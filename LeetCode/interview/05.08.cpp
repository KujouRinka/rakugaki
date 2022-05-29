class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        int line_size = w / 32;
        vector<int> r(length, 0);
        int head_grp = x1 / 32, head_p = x1 % 32;
        int tail_grp = x2 / 32, tail_p = x2 % 32;
        uint32_t rep1 = head_p == 0 ? 0xffffffff : (1u << (32 - head_p)) - 1;
        uint32_t rep2 = tail_p == 31 ? 0xffffffff : ~((1u << (31 - tail_p)) - 1);
        if (head_grp == tail_grp) {
            r[y * line_size + head_grp] = rep1 & rep2;
        } else {
            r[y * line_size + head_grp] = rep1;
            r[y * line_size + tail_grp] = rep2;
        }
        for (int i = y * line_size + head_grp + 1; i < y * line_size + tail_grp; ++i)
            r[i] = -1;
        return std::move(r);
    }
};

