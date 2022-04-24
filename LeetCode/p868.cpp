class Solution {
public:
    int binaryGap(int n) {
        int previous = 0;
        while (n > 0 && (n & 1) == 0) {
            ++previous;
            n >>= 1;
        }
        n >>= 1;
        int current;
        int max_gap = 0;
        while (n > 0) {
            current = previous + 1;
            while (n > 0 && (n & 1) == 0) {
                ++current;
                n >>= 1;
            }
            n >>= 1;
            max_gap = max(max_gap, current - previous);
            previous = current;
        }
        return max_gap;
    }
};

