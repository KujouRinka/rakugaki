class Solution {
public:
    int countBattleships(const vector<vector<char>> &board) {
        int count = 0;
        int sz_y = board.size();
        int sz_x = board[0].size();
        for (int i = 0; i < sz_y; ++i) {
            for (int j = 0; j < sz_x; ++j) {
                if (valid(board, j, i))
                    ++count;
            }
        }
        return count;
    }

    static bool valid(const vector<vector<char>> &board, int x, int y) {
        if (board[y][x] != 'X')
            return false;
        int nx = x - 1, ny = y - 1;
        if (nx >= 0 && ny >= 0) {
            return board[y][nx] == '.' && board[ny][x] == '.';
        } else if (nx >= 0) {
            return board[y][nx] == '.';
        } else if (ny >= 0) {
            return board[ny][x] == '.';
        } else {
            return true;
        }
    }
};

