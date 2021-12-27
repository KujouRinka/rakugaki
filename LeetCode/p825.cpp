class Solution {
public:
    int numFriendRequests(vector<int> &ages) {
        int result = 0;
        sort(ages.begin(), ages.end());
        int sz = ages.size();
        int p_front = 0, p_back = 0;
        for (int i = 0; i < sz; ++i) {
            while (p_front < i && !check(ages[i], ages[p_front]))
                ++p_front;
            if (p_back < i)
                p_back = i;
            while (p_back < sz && check(ages[i], ages[p_back]))
                ++p_back;
            if (p_back > p_front)
                result += p_back - p_front - 1;
        }
        return result;
    }

private:
    static bool check(int x, int y) {
        if (2 * y <= x + 14)
            return false;
        if (y > x)
            return false;
        if (y > 100 && x < 100)
            return false;
        return true;
    }
};

