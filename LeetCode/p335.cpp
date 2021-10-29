class Solution {
public:
    bool isSelfCrossing(const vector<int> &distance) {
        auto sz = distance.size();
        if (sz < 4)
            return false;
        for (int i = 3; i < sz; ++i) {
            int d, d1, d2, d3, d4, d5;
            d = distance[i];
            d1 = distance[i - 1];
            d2 = distance[i - 2];
            d3 = distance[i - 3];
            if (i > 3)
                d4 = distance[i - 4];
            if (i > 4)
                d5 = distance[i - 5];
            if (d1 <= d3 && d >= d2)
                return true;
            if (i > 3 && d3 == d1 && d + d4 >= d2)
                return true;
            auto t1 = d3 - d1;
            if (i > 4 && t1 >= 0 && t1 <= d5 && d2 >= d4 && d + d4 >= d2)
                return true;
        }
        return false;
    }
};
