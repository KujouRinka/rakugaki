class Solution {
public:
    int maxIncreaseKeepingSkyline(const vector<vector<int>> &grid) {
        int horizontal_sz = grid[0].size();
        int vertical_sz = grid.size();
        vector<int> horizontal_max(horizontal_sz);
        vector<int> vertical_max(vertical_sz);
        for (int i = 0; i < vertical_sz; ++i) {
            for (int j = 0; j < horizontal_sz; ++j) {
                horizontal_max[j] = max(horizontal_max[j], grid[i][j]);
                vertical_max[i] = max(vertical_max[i], grid[i][j]);
            }
        }

        int volume = 0;
        for (int i = 0; i < vertical_sz; ++i) {
            for (int j = 0; j < horizontal_sz; ++j) {
                volume += min(horizontal_max[j], vertical_max[i]) - grid[i][j];
            }
        }
        return volume;
    }
};

