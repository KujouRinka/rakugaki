class Solution {
public:
    int lastRemaining(int n) {
        return findIdx(n, true) + 1;
    }

private:
    static int findIdx(int n, bool dir) {
        if (n == 1)
            return 0;

        if (dir) {
            return findIdx(n / 2, false) * 2 + 1;
        } else {
            if (n & 1)
                return findIdx(n / 2, true) * 2 + 1;
            return findIdx(n / 2, true) * 2;
        }
    }
};

