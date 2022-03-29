class Solution {
public:
    int maxConsecutiveAnswers(const string &answerKey, int k) {
        auto f = [&answerKey, k](char flip) -> int {
            int left_p = 0, right_p = 0;
            int sz = answerKey.size();
            int in_count = 0;
            int max_len = 0;

            while (right_p < sz) {
                while (right_p < sz && (answerKey[right_p] != flip || in_count < k)) {
                    if (answerKey[right_p] == flip)
                        ++in_count;
                    ++right_p;
                }
                max_len = max(max_len, right_p - left_p);
                while (left_p < right_p && answerKey[left_p] != flip)
                    ++left_p;
                ++left_p;
                --in_count;
            }
            return max_len;
        };

        return max(f('T'), f('F'));
    }
};

