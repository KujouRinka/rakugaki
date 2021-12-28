class Solution {
public:
    void reverseString(vector<char>& s) {
        int p_front = 0, p_back = s.size() - 1;
        while (p_front < p_back) {
            swap(s[p_front++], s[p_back--]);
        }
    }
};

