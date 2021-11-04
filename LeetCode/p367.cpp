class Solution {
public:
    bool isPerfectSquare(int num) {
        long int i = 0;
        while (i * i <= num) {
            if (i * i == num)
                return true;
            ++i;
        }
        return false;
    }
};
