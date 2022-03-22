class Solution {
public:
    bool winnerOfGame(const string &colors) {
        int A_count = 0, B_count = 0;
        int sz = colors.size() - 1;
        for (int i = 1; i < sz; ++i) {
            if (colors[i] == 'A' && colors[i - 1] == 'A' && colors[i + 1] == 'A')
                ++A_count;
            else if (colors[i] == 'B' && colors[i - 1] == 'B' && colors[i + 1] == 'B')
                ++B_count;
        }
        return A_count > B_count;
    }
};

