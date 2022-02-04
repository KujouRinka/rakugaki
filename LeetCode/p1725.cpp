class Solution {
public:
    int countGoodRectangles(vector<vector<int>> &rectangles) {
        int max_len = -1;
        int count = 0;
        for (auto &rec: rectangles) {
            int side = min(rec[0], rec[1]);
            if (side == max_len) {
                ++count;
            } else if (side > max_len) {
                max_len = side;
                count = 1;
            }
        }

        return count;
    }
};

