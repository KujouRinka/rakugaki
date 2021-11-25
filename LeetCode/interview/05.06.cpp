class Solution {
public:
    int convertInteger(int A, int B) {
        int j = A ^ B;
        uint32_t *i = reinterpret_cast<uint32_t *>(&j);
        int count = 0;
        while (*i) {
            if (*i & 1)
                ++count;
            *i >>= 1;
        }
        return count;
    }
};
