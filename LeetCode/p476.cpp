class Solution {
public:
    int findComplement(int num) {
        uint32_t x = 1;
        for (uint32_t i = num; i != 0;) {
            i -= i & x;
            x <<= 1;
        }
        return ~num & (x - 1);
    }
};
