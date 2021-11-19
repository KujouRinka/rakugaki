class Solution {
    unordered_map<int, int> m;
public:
    int integerReplacement(int n) {
        if (n == 1)
            return 0;
        if (m.count(n))
            return m[n];
        if (n & 1)
            return m[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
        return m[n] = 1 + integerReplacement(n / 2);
    }
};
