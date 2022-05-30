class Solution {
public:
    vector<vector<int>> pathWithObstacles(const vector<vector<int>> &obstacleGrid) {
        int x, y;
        if (y = obstacleGrid.size(); y == 0)
            return {};
        if (x = obstacleGrid[0].size(); x == 0)
            return {};
        vector<vector<pair<int, int>>> dp(y, vector<pair<int, int>>(x, {-1, -1}));    // {x, y}
        if (obstacleGrid.back().back() == 1)
            return {};
        dp.back().back() = {-0x7fffffff, -0x7fffffff};
        int px = x - 1, py = y - 1;
        for (int i = px - 1; i >= 0 && obstacleGrid[py][i] != 1; --i)   // (i, py)
            dp[py][i] = {i + 1, py};
        for (int i = py - 1; i >= 0 && obstacleGrid[i][px] != 1; --i)   // (px, i)
            dp[i][px] = {px, i + 1};
        for (int cy = py - 1; cy >= 0; --cy) {
            for (int cx = px - 1; cx >= 0; --cx) {
                if (obstacleGrid[cy][cx] == 1)
                    continue;
                if (dp[cy + 1][cx] != pair<int, int>(-1, -1))
                    dp[cy][cx] = {cx, cy + 1};
                else if (dp[cy][cx + 1] != pair<int, int>(-1, -1))
                    dp[cy][cx] = {cx + 1, cy};
            }
        }
        if (dp[0][0] == pair<int, int>(-1, -1))
            return {};
        vector<vector<int>> r;
        r.push_back({0, 0});    // {y, x}
        vector<int> end{y - 1, x - 1};
        while (r.back() != end) {
            int nx = dp[r.back()[0]][r.back()[1]].first;
            int ny = dp[r.back()[0]][r.back()[1]].second;
            r.push_back({ny, nx});
        }
        return r;
    }
};

