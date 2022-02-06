class Solution {
public:
    int sumOfUnique(vector<int> &nums) {
        int black_list[101] = {0};
        int sum = 0;
        for (int i: nums) {
            if (black_list[i]) {
                if (black_list[i] == 1) {
                    sum -= i;
                    black_list[i] = 2;
                }
            } else {
                sum += i;
                black_list[i] = 1;
            }
        }
        return sum;
    }
};

