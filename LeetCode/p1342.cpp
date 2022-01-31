class Solution {
public:
    int numberOfSteps(int num) {
        uint32_t u = num;
        int result = 0;
        while (true) {
            if (u & 1)
                ++result;
            u >>= 1;
            if (u == 0)
                break;
            ++result;
        }
        return result;
    }
};

