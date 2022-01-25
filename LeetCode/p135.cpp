class Solution {
public:
    int candy(const vector<int> &ratings) {
        auto sz = ratings.size();
        vector<int> tv(sz, 1);
        for (int i = 1; i < sz; ++i) {
            if (ratings[i] > ratings[i - 1])
                tv[i] = tv[i - 1] + 1;
        }
        for (int i = sz - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1])
                tv[i] = max(tv[i], tv[i + 1] + 1);
        }
        return accumulate(tv.begin(), tv.end(), 0);
    }
};

