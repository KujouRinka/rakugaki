const char *row_idx = "12210111011122000010020202";

class Solution {
public:
    vector<string> findWords(vector<string> &words) {
        vector<string> result;
        for (string &word: words) {
            char line = row_idx[tolower(word[0]) - 'a'];
            bool f = true;
            for (int i = 1; i < word.size(); ++i) {
                if (line != row_idx[tolower(word[i]) - 'a'])
                    goto go;
            }
            result.push_back(word);
            go:;
        }
        return result;
    }
};
