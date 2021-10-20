class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int get = 1;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            if (get == 0)
                break;
            *it += get;
            get = *it / 10;
            *it %= 10;
        }
        if (get == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
