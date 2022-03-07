class Solution {
public:
    string convertToBase7(int num) {
        bool neg = num < 0;
        if (neg)
            num = -num;
        string r;
        do {
            r.push_back(num % 7 + '0');
            num /= 7;
        } while (num != 0);
        if (neg)
            r.push_back('-');
        return {r.crbegin(), r.crend()};
    }
};

