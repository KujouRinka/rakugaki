class Solution {
public:
    int movingCount(int m, int n, int k) {
        _y_sz = m;
        _x_sz = n;
        _k = k;
        _result = 0;
        _visited = vector<vector<bool>>(_y_sz, vector<bool>(_x_sz, false));
        dfs(0, 0);
        return _result;
    }

private:
    int _k;
    int _x_sz, _y_sz;
    int _result;
    vector<vector<bool>> _visited;
    static const int dirs[4][2];

    void dfs(int x, int y) {
        if (!isValid(x, y) || _visited[y][x] || !canReach(x, y))
            return;
        ++_result;
        _visited[y][x] = true;
        for (auto &dir: dirs) {
            int nx = x + dir[0], ny = y + dir[1];
            dfs(nx, ny);
        }
    }

    bool canReach(int x, int y) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        while (y > 0) {
            sum += y % 10;
            y /= 10;
        }
        return sum <= _k;
    }

    bool isValid(int x, int y) {
        return x >= 0 && x < _x_sz && y >= 0 && y < _y_sz;
    }
};

const int Solution::dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

