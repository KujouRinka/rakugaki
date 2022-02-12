class Solution {
public:
    int maxNumberOfBalloons(const string &text) {
        int count[5] = {0}; // b a l o n
        for (char ch: text) {
            switch (ch) {
                case 'b':
                    ++count[0];
                    break;
                case 'a':
                    ++count[1];
                    break;
                case 'l':
                    ++count[2];
                    break;
                case 'o':
                    ++count[3];
                    break;
                case 'n':
                    ++count[4];
                    break;
                default:
                    break;
            }
        }
        int min_val = 0x7fffffff;
        min_val = min(min_val, min(
                count[0], min(
                        count[1], min(
                                count[2] / 2, min(
                                        count[3] / 2, count[4])))));
        return min_val;
    }
};

