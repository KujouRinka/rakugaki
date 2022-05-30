class Solution {
public:
    vector<vector<int>> pathWithObstacles(const vector<vector<int>> &obstacleGrid) {
        if (_y = obstacleGrid.size(); _y == 0)
            return {};
        if (_x = obstacleGrid[0].size(); _x == 0)
            return {};
        _grid_cp = obstacleGrid;
        backtracking(0, 0);
        return _path;
    }

private:
    size_t _x, _y;
    vector<vector<int>> _grid_cp;
    vector<vector<int>> _path;

    bool backtracking(int x, int y) {
        if (x >= _x || y >= _y || _grid_cp[y][x] == 1)
            return false;
        _path.push_back({y, x});
        if (x == _x - 1 && y == _y - 1)
            return true;
        if (backtracking(x + 1, y))
            return true;
        if (backtracking(x, y + 1))
            return true;
        _path.pop_back();
        return false;
    }
};

