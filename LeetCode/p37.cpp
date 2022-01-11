class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        backtracking(board, 0, 0);
    }

private:
    bool backtracking(vector<vector<char>> &board, int x, int y) {
        if (y == 9)
            return true;
        auto[nx, ny] = next(x, y);
        if (board[y][x] == '.') {
            for (int i = 1; i <= 9; ++i) {
                if (!check(board, x, y, toChar(i)))
                    continue;
                board[y][x] = toChar(i);
                bool r = backtracking(board, nx, ny);
                if (r)
                    return true;
                board[y][x] = '.';
            }
        } else {
            bool r = backtracking(board, nx, ny);
            if (r)
                return true;
        }
        return false;
    }

    static bool check(vector<vector<char>> &board, int x, int y, char value) {
        for (int i = 0; i < 9; ++i) {
            if (board[y][i] == value)
                return false;
            if (board[i][x] == value)
                return false;
        }
        int start_x = x / 3 * 3;
        int start_y = y / 3 * 3;
        for (int i = 0; i < 3; ++i) {
            int ny = start_y + i;
            for (int j = 0; j < 3; ++j) {
                int nx = start_x + j;
                if (board[ny][nx] == value)
                    return false;
            }
        }
        return true;
    }

    static inline pair<int, int> next(int x, int y) {
        if (x == 8)
            return {0, y + 1};
        return {x + 1, y};
    }

    static inline char toChar(int i) {
        return i + '0';
    }
};

