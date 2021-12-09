class Solution {
public:
    bool validTicTacToe(const vector<string> &board) {
        int XCount = 0, OCount = 0;
        int discard = 0;
        for (const string &s: board) {
            for (char ch: s)
                ++(ch == 'X' ? XCount : (ch == 'O' ? OCount : discard));
        }
        bool XWin = isWin(board, 'X');
        bool OWin = isWin(board, 'O');
        if (XWin && OWin)
            return false;
        if (XWin)
            return XCount - OCount == 1;
        if (OWin)
            return XCount == OCount;
        return XCount - OCount == 1 || XCount == OCount;
    }

    static bool isWin(const vector<string> &board, char winner) {
        const string &l0 = board[0], &l1 = board[1], &l2 = board[2];
        if (l0[0] == l0[1] && l0[1]) {

        }
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == winner && board[i][0] == board[i][1] && board[i][0] == board[i][2])
                return true;
            if (board[0][i] == winner && board[0][i] == board[1][i] && board[0][i] == board[2][i])
                return true;
        }
        if (board[0][0] == winner && board[0][0] == board[1][1] && board[0][0] == board[2][2])
            return true;
        if (board[2][0] == winner && board[2][0] == board[1][1] && board[2][0] == board[0][2])
            return true;

        return false;
    }
};

