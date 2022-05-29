class Solution {
public:
    string validIPAddress(const string &queryIP) {
        auto start = queryIP.c_str();
        if (auto v4 = split(queryIP, '.'); v4.size() == 4) {
            for (auto[f, b]: v4) {
                int i;
                if ((b - f == 0) || (b - f > 3) || ((b - f) != 1 && *(start + f) == '0'))
                    return "Neither";
                auto rp = from_chars(start + f, start + b, i).ptr;
                if (!(i >= 0 && i < 256) || (b - f != rp - (start + f)))
                    return "Neither";
            }
            return "IPv4";
        } else if (auto v6 = split(queryIP, ':'); v6.size() == 8) {
            for (auto[f, b]: v6) {
                if (b - f > 4 || b - f <= 0)
                    return "Neither";
                int i;
                auto rp = from_chars(start + f, start + b, i, 16).ptr;
                if (rp - (start + f) != (b - f))
                    return "Neither";
            }
            return "IPv6";
        }
        return "Neither";
    }

public:
    static vector<pair<int, int>> split(const string &s, char ch) {
        int start = 0, end = -1;
        auto sz = s.size();
        vector<pair<int, int>> r;
        while (start < sz) {
            ++end;
            start = end;
            while (end < sz && s[end] != ch)
                ++end;
            r.emplace_back(start, end);
            start = end;
        }
        return std::move(r);
    }
};

