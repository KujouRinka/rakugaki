class Solution {
public:
    string replaceSpaces(string S, int length) {
        int space_count = 0;
        for (int i = 0; i < length; ++i)
            if (S[i] == ' ')
                ++space_count;
        S.resize(length + 2 * space_count);
        int insert_ind = S.size() - 1;
        for (int i = length - 1; i >= 0; --i) {
            if (i == insert_ind)
                break;
            if (S[i] != ' ') {
                S[insert_ind--] = S[i];
            } else {
                S[insert_ind--] = '0';
                S[insert_ind--] = '2';
                S[insert_ind--] = '%';
            }
        }
        return S;
    }
};
