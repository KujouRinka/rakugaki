class Solution {
public:
    bool exist(const vector<vector<char>> &board, const string &word) {
        _s = word;
        _board = board;
        x_size = board[0].size();
        y_size = board.size();
        _used = vector<vector<bool>>(y_size, vector<bool>(x_size, false));
        for (int y = 0; y < y_size; ++y) {
            for (int x = 0; x < x_size; ++x) {
                if (realExist(x, y, 0))
                    return true;
            }
        }
        return false;
    }

private:
    string _s;
    int x_size, y_size;
    vector<vector<bool>> _used;
    vector<vector<char>> _board;
    static const int dirs[4][2];

    bool realExist(int x, int y, int idx) {
        if (idx == _s.size())
            return true;
        if (!isValid(x, y) || _used[y][x] || _board[y][x] != _s[idx])
            return false;
        _used[y][x] = true;
        for (auto dir: dirs) {
            int nx = x + dir[0], ny = y + dir[1];
            if (realExist(nx, ny, idx + 1))
                return true;
        }
        _used[y][x] = false;
        return false;
    }

    bool isValid(int x, int y) {
        return x >= 0 && x < x_size && y >= 0 && y < y_size;
    }
};

const int Solution::dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

