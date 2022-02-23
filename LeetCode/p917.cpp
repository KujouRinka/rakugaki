class Solution {
public:
    string reverseOnlyLetters(string s) {
        int p_left = 0, p_right = s.size();
        while (p_left < p_right) {
            while (p_left < p_right && !isalpha(s[p_left]))
                ++p_left;
            while (p_left < p_right && !isalpha(s[p_right]))
                --p_right;
            swap(s[p_left++], s[p_right--]);
        }
        return s;
    }
};

