class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.size() == 0)
            return 0;
        sort(points.begin(), points.end());
        int arrow = 1;
        int min_t = 0x7fffffff;
        for (auto & point : points) {
            auto &p = point;
            if (p[0] <= min_t) {
                min_t = min(min_t, p[1]);
            } else {
                ++arrow;
                min_t = point[1];
            }
        }
        return arrow;
    }
};

