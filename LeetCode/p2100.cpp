class Solution {
public:
    vector<int> goodDaysToRobBank(const vector<int> &security, int time) {
        auto sz = security.size();
        int t_sz = sz - time * 2;
        if (t_sz <= 0)
            return {};
        vector<int> pre_desc(t_sz);
        vector<int> after_incr(t_sz);
        vector<int> r;
        int d_desc = 0, d_incr = 0;
        for (int i = 1; i <= time; ++i) {
            if (security[i] <= security[i - 1])
                ++d_desc;
            else
                d_desc = 0;
            int bi = sz - i - 1;
            if (security[bi] <= security[bi + 1])
                ++d_incr;
            else
                d_incr = 0;
        }
        pre_desc[0] = d_desc;
        after_incr.back() = d_incr;
        for (int i = 1, sec_i = time + 1; i < t_sz; ++i, ++sec_i) {
            if (security[sec_i] <= security[sec_i - 1])
                pre_desc[i] = pre_desc[i - 1] + 1;
            else
                pre_desc[i] = 0;
            int sec_bi = sz - i - time - 1;
            if (security[sec_bi] <= security[sec_bi + 1])
                after_incr[t_sz - i - 1] = after_incr[t_sz - i] + 1;
            else
                after_incr[t_sz - i - 1] = 0;
        }

        for (int i = time; i < sz - time; ++i) {
            if (pre_desc[i - time] >= time && after_incr[i - time] >= time)
                r.push_back(i);
        }
        return r;
    }
};

