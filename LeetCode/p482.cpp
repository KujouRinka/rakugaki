using namespace std;
class Solution {
    static bool f(char ch) {
        return isalnum(ch);
    }

public:
    string licenseKeyFormatting(const string &s, int k) {
        auto charCount = count_if(s.begin(), s.end(), f);
        auto n = charCount % k;
        auto times = charCount / k;
        string result;
        result.reserve(s.size() * 1.2);
        auto it = s.begin();
        for (int i = 0; i < n; ++i) {
            it = find_if(it, s.end(), f);
            result.push_back(toupper(*it++));
        }

        for (int i = 0; i < times; ++i) {
            if (!result.empty())
                result.push_back('-');
            for (int j = 0; j < k; ++j) {
                for (; isalnum(*it) == 0; ++it)
                    ;
                result.push_back(toupper(*it++));
            }
        }

        return result;
    }
};
