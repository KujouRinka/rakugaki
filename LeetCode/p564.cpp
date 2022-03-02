class Solution {
    using ll = long long;

public:
    string nearestPalindromic(const string &n) {
        auto length = n.size();
        bool isOdd = length & 1;
        ll current = stoll(n, nullptr);
        unordered_set<ll> r_set;
        r_set.insert(pow(10, length) + 1ll);
        r_set.insert(pow(10, length - 1) - 1ll);
        int mid = (length + 1) / 2;
        ll pre_i;
        from_chars(n.c_str(), n.c_str() + mid, pre_i);
        for (int i = -1; i <= 1; ++i) {
            ll t = getNum(pre_i + i, isOdd);
            if (t != current)
                r_set.insert(t);
        }

        ll ab = INT64_MAX;
        ll r = -1;
        for (ll i: r_set) {
            if (abs(i - current) < ab) {
                r = i;
                ab = abs(i - current);
            } else if (abs(i - current) == ab && i < r) {
                r = i;
            }
        }
        return to_string(r);
    }

private:
    static ll getNum(ll prefix, bool isOdd) {
        ll t = prefix;
        if (isOdd)
            t /= 10;
        while (t > 0) {
            prefix *= 10;
            prefix += t % 10;
            t /= 10;
        }
        return prefix;
    }
};

