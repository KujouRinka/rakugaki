class Solution {
public:
    string getHint(const string &secret, const string &guess) {
        int A_count = 0, B_count = 0;
        int mismatch_A_count[10] = {0};
        int mismatch_B_count[10] = {0};
        int sz = secret.size();
        for (int i = 0; i < sz; ++i) {
            if (secret[i] == guess[i]) {
                ++A_count;
            } else {
                ++mismatch_A_count[secret[i] - '0'];
                ++mismatch_B_count[guess[i] - '0'];
            }
        }
        for (int i = 0; i < 10; ++i)
            B_count += min(mismatch_A_count[i], mismatch_B_count[i]);
        return to_string(A_count) + "A" + to_string(B_count) + "B";
    }
};
