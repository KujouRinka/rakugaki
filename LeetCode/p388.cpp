class Solution {
public:
    int lengthLongestPath(const string &input) {
        int max_length = 0;
        int cur_len = 0;
        int deep = 0;
        vector<string> memo;
        stringstream ss(input);
        string line;
        while (getline(ss, line)) {
            int counter = 0;
            while (line[counter] == '\t')
                ++counter;
            if (counter == deep) {
                cur_len += line.size() - counter;
                memo.emplace_back(line.begin() + counter, line.end());
                ++deep;
            } else {
                if (memo.back().find('.') != string::npos)
                    max_length = max<int>(max_length, cur_len + memo.size());
                int back = deep - counter;
                deep -= back;
                while (back--) {
                    cur_len -= memo.back().size();
                    memo.pop_back();
                }
                ++deep;
                cur_len += line.size() - counter;
                memo.emplace_back(line.begin() + counter, line.end());
            }
        }
        if (memo.back().find('.') != string::npos)
            max_length = max<int>(max_length, cur_len + memo.size());

        return max(max_length - 1, 0);
    }
};

