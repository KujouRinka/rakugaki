class Solution {
public:
    int add(int a, int b) {
        int res = a ^ b;
        uint carry = a & b;
        while (carry != 0) {
            carry <<= 1;
            int t = res ^ carry;
            carry = res & carry;
            res = t;
        }
        return res;
    }
};

