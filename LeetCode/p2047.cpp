class Solution {
public:
    int countValidWords(const string &sentence) {
        int count = 0;
        auto sz = sentence.size();
        int p_front = 0, p_back = 0;
        while (true) {
            while (sentence[p_front] == ' ')
                ++p_front;
            p_back = p_front;
            bool valid = true;
            int hyphen_count = 0;
            int dot_count = 0;
            while (p_back < sz && sentence[p_back] != ' ') {
                char ch = sentence[p_back];
                if (isalpha(ch)) {
                    // pass
                } else if (ch == '-') {
                    if (!(p_back - 1 >= 0 && isalpha(sentence[p_back - 1]) &&
                          p_back + 1 < sz && isalpha(sentence[p_back + 1])))
                        valid = false;
                    ++hyphen_count;
                } else if (ch == ',' || ch == '.' || ch == '!') {
                    if (p_back + 1 != sz && sentence[p_back + 1] != ' ')
                        valid = false;
                    ++dot_count;
                } else {
                    valid = false;
                }
                ++p_back;
            }
            if (hyphen_count > 1 || dot_count > 1 || p_front == sz)
                valid = false;
            p_front = p_back;

            if (valid)
                ++count;
            if (p_back >= sz)
                break;
        }
        return count;
    }
};

