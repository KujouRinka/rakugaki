class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> result;
        string s;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (gcd(i, j) != 1)
                    continue;
                s.clear();
                s.append(std::move(to_string(i)))
                        .append(1, '/')
                        .append(std::move(to_string(j)));
                result.emplace_back(std::move(s));
            }
        }
        return result;
    }

private:
    static int gcd(int a, int b) {
        while (b != 0) {
            int c = a;
            a = b;
            b = c % b;
        }
        return a;
    }
};

