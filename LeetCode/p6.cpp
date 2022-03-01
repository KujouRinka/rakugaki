class Solution {
public:
    string convert(const string &s, int numRows) {
        if (numRows == 1)
            return s;
        int delta = (numRows - 1) * 2;
        auto sz = s.size();
        string result;
        result.reserve(sz);

        for (int i = 0; i < numRows; ++i) {
            int first = i;
            int second = 2 * numRows - i - 2;
            for (int j = 0;; ++j) {
                int idx = first + j * delta;
                if (idx >= sz)
                    break;
                result.push_back(s[idx]);
                if (i != 0 && i != numRows - 1) {
                    idx = second + j * delta;
                    if (idx >= sz)
                        break;
                    result.push_back(s[idx]);
                }
            }
        }
        return result;
    }
};

