class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        uint32_t mask = ~(((~0u) >> (31 - j + i)) << i);
        return (N & mask) | (M << i);
    }
};
