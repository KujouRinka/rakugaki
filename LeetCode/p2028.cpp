class Solution {
public:
    vector<int> missingRolls(const vector<int> &rolls, int mean, int n) {
        auto sz = rolls.size();
        int sub = mean * (sz + n) - accumulate(rolls.begin(), rolls.end(), 0);
        if (sub < n || sub > n * 6)
            return {};
        vector<int> result(n, sub / n);
        int max_add = 6 - sub / n;
        if (max_add == 0)
            return result;
        for (int i = sub % n / max_add - 1; i >= 0; --i)
            result[i] += max_add;
        result.back() += sub % n % max_add;
        return result;
    }
};

