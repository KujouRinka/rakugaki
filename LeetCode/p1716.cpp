class Solution {
public:
    int totalMoney(int n) {
        int full_week = n / 7;
        int first_item = 28;
        int last_item = first_item + 7 * (full_week - 1);
        int t1 = (first_item + last_item) * full_week / 2;
        int t2 = (1 + n % 7 + 2 * full_week) * (n % 7) / 2;
        return t1 + t2;
    }
};

