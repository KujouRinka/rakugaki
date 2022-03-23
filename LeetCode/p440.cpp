class Solution {
public:
    int findKthNumber(int n, int k) {
        int prefix = 1;
        while (k > 1) {
            int cnt = getCount(prefix, n);
            if (k > cnt) {
                k -= cnt;
                ++prefix;
            } else {
                --k;
                prefix *= 10;
            }
        }
        return prefix;
    }

private:
    int getCount(int x, int limit) {
        int x_len = 0, limit_len = 0;
        for (int _x = x; _x > 0; _x /= 10)
            ++x_len;
        for (int _limit = limit; _limit > 0; _limit /= 10)
            ++limit_len;
        int cnt = 0;
        for (int i = x_len, fac = 0; i < limit_len; ++i, ++fac)
            cnt += pow(10, fac);
        int u = limit / pow(10, limit_len - x_len);
        if (u > x)
            cnt += pow(10, limit_len - x_len);
        else if (u == x)
            cnt += limit - x * pow(10, limit_len - x_len) + 1;
        return cnt;
    }
};

