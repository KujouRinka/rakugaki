class Solution {
public:
    string compressString(string &s) {
        auto start = s.begin(), end = s.begin();
        string result;
        result.reserve(s.size() * 2);
        while (end != s.end()) {
            while (end != s.end() && *start == *end)
                ++end;
            result.push_back(*start);
            result += to_string(end - start);
            start = end;
        }
        return s.size() > result.size() ? result : s;
    }
};
