class Solution {
public:
    int thirdMax(const vector<int> &nums) {
        int64_t a, b, c;
        a = b = c = -0xffffffffll;
        for (auto i: nums) {
            if (i > c) {
                a = b;
                b = c;
                c = i;
            } else if (i > b && i < c) {
                a = b;
                b = i;
            } else if (i > a && i < b) {
                a = i;
            }
        }
        return a == -0xffffffffll ? c : a;
    }
};
