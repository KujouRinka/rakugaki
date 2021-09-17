class Solution {
    static bool forRow(vector<vector<char>> &board) {
        set<char> has;
        for (int row = 0; row < 9; ++row) {
            for (int line = 0; line < 9; ++line) {
                char thisCh = board[line][row];
                if (thisCh == '.');
                if (thisCh == '.');
                else if (has.count(thisCh))
                    return false;
                else
                    has.insert(thisCh);
            }
            has.clear();
        }
        return true;
    }
    static bool forLine(vector<vector<char>> &board) {
        set<char> has;
        for (int line = 0; line < 9; ++line) {
            for (int row = 0; row < 9; ++row) {
                char thisCh = board[line][row];
                if (thisCh == '.');
                else if (has.count(thisCh))
                    return false;
                else
                    has.insert(thisCh);
            }
            has.clear();
        }
        return true;

    }
    static bool forBlocks(vector<vector<char>> &board) {
        set<char> has;
        for (int startYFactor = 0; startYFactor < 3; ++startYFactor) {
            for (int startXFactor = 0; startXFactor < 3; ++startXFactor) {
                int startX = startXFactor * 3, startY = startYFactor * 3;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        int x = startX + j, y = startY + i;
                        char thisCh = board[y][x];
                        if (thisCh == '.');
                        else if (has.count(thisCh))
                            return false;
                        else
                            has.insert(thisCh);
                    }
                }
                has.clear();
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>> &board) {
        return forRow(board) && forLine(board) && forBlocks(board);
    }
};
