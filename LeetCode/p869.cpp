static unordered_set<string> pow_set;

string digitToStr(int n) {
    string s(10, 0);
    for (; n > 0; n /= 10)
        ++s[n % 10];
    return s;
}

int i = []() -> int {
    for (int i = 1; i < 1e9; i <<= 1)
        pow_set.insert(digitToStr(i));
    return 0;
}();

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        return pow_set.count(digitToStr(n)) != 0;
    }
};
