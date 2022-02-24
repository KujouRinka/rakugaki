class Solution {
public:
    vector<int> findBall(const vector<vector<int>> &grid) {
        sz_x = grid[0].size();
        sz_y = grid.size();
        vector<int> result;
        result.reserve(sz_x);

        for (int i = 0; i < sz_x; ++i) {
            int x = i;
            int y = 0;
            int nx;
            for (; y < sz_y; ++y) {
                nx = x + grid[y][x];
                if (!isValidX(nx) || grid[y][x] != grid[y][nx]) {
                    result.push_back(-1);
                    break;
                }
                x = nx;
            }
            if (!isValidY(y))
                result.push_back(nx);
        }
        return result;
    }

private:
    size_t sz_x;
    size_t sz_y;

    inline bool isValidX(int x) {
        return x >= 0 && x < sz_x;
    }

    inline bool isValidY(int y) {
        return y >= 0 && y < sz_y;
    }
};

