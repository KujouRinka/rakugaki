class Solution {
public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        int front = 0, back = 0;
        unordered_set<string> _s;
        for (auto &s: banned)
            _s.emplace(s);
        unordered_map<string, int> count_map;
        while (front < paragraph.size() && back < paragraph.size()) {
            while (front < paragraph.size() && !isalpha(paragraph[front]))
                ++front;
            back = front;
            while (back < paragraph.size() && isalpha(paragraph[back]))
                ++back;
            auto cur_s = paragraph.substr(front, back - front);
            transform(cur_s.begin(), cur_s.end(), cur_s.begin(), [](char ch) { return tolower(ch); });
            if (back > front && _s.count(cur_s) == 0)
                ++count_map[move(cur_s)];
            front = back;
        }
        int max_count = 0;
        string result;
        for (auto &r: count_map) {
            if (r.second > max_count) {
                max_count = r.second;
                result = r.first;
            }
        }
        return result;
    }
};

