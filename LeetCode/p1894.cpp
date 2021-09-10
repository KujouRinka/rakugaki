class Solution {
public:
    int chalkReplacer(const vector<int> &chalk, int k) {
        auto sum = accumulate(chalk.begin(), chalk.end(), static_cast<int64_t>(0));
        auto lastCir = k % sum;
        int ind = 0;
        do {
            lastCir -= chalk[ind];
        } while (lastCir >= 0 && ++ind);
        return ind;
    }
};
