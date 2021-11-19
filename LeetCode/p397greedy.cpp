class Solution {
public:
    int integerReplacement(int n) {
        int cnt = 0;
        while (n != 1) {
            if (!(n & 1)) {
                n >>= 1;
                ++cnt;
            } else if (n % 4 == 1) {
                n >>= 1;
                cnt += 2;
            } else {
                if (n == 3) {
                    n = 1;
                    cnt += 2;
                } else {
                    n = (n >> 1) + 1;
                    cnt += 2;
                }
            }
        }
        return cnt;
    }
};
