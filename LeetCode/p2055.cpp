class Solution {
public:
    vector<int> platesBetweenCandles(const string &s, const vector<vector<int>> &queries) {
        auto sz = s.size();
        vector<int> ps(sz + 1);
        vector<int> candles_idx;
        for (int i = 0; i < sz; ++i) {
            if (s[i] == '*') {
                ps[i + 1] = ps[i];
            } else {
                ps[i + 1] = ps[i] + 1;
                candles_idx.push_back(i);
            }
        }
        vector<int> r;
        r.reserve(queries.size());
        for (auto &query: queries) {
            auto left_it = lower_bound(candles_idx.begin(), candles_idx.end(), query[0]);
            auto right_it = upper_bound(candles_idx.begin(), candles_idx.end(), query[1]);
            int t;
            int left, right;
            if (left_it == candles_idx.end() || right_it == candles_idx.begin() ||
                (left = *left_it) >= (right = *(right_it - 1)))
                t = 0;
            else
                t = (right - left + 1) - (ps[right + 1] - ps[left]);
            r.push_back(t);
        }
        return r;
    }
};

