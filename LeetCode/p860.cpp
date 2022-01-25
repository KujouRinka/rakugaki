class Solution {
public:
    bool lemonadeChange(const vector<int> &bills) {
        int note[3] = {0};
        for (int i: bills) {
            if (!f(i - 5, note))
                return false;
            ++note[box(i)];
        }
        return true;
    }

private:
    static inline bool f(int change, int *note) {
        if (10 < change && note[1] > 0) {
            --note[1];
            change -= 10;
        }
        int k = change / 5;
        if (note[0] < k) {
            return false;
        }
        note[0] -= k;
        return true;
    }

    static inline int box(int i) {
        switch (i) {
            case 20:
                return 2;
            case 10:
                return 1;
            case 5:
                return 0;
            default:
                return -1;
        }
    }
};

