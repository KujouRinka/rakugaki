class Solution {
public:
    string reverseWords(const string &s) {
        vector<pair<int, int>> words;
        split(words, s);
        string result;
        for (auto rit = words.crbegin(); rit != words.crend(); ++rit)
            result.append(s.c_str() + rit->first, rit->second - rit->first)
                    .append(" ", 1);
        if (!result.empty())
            result.pop_back();
        return result;
    }

private:
    void split(vector<pair<int, int>> &words, const string &s) {
        int front = 0, back = 0;
        auto end = s.size();
        while (front < end) {
            front = back;
            while (front < end && isspace(s[front]))
                ++front;
            back = front;
            while (back < end && !isspace(s[back]))
                ++back;
            if (front < back)
                words.emplace_back(front, back);
        }
    }
};
