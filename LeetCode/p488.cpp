class Solution {
    int result = 0x7fffffff;
    unordered_map<char, int> ball;
    stack<pair<char, int>> node;
    int used = 0;

public:
    int findMinStep(string board, const string &hand) {
        for (char ch: hand)
            ++ball[ch];

        dfs(board, 0);

        return result == 0x7fffffff ? -1 : result;
    }

private:
    void dfs(string &board, int pos) {
        if (used >= result)
            return;
        if (pos == board.size()) {
            if (node.empty())
                result = used;
            return;
        }

        if (!node.empty() && node.top().first == board[pos])
            node.top().second++;
        else
            node.emplace(board[pos], 1);

        if (node.top().second >= 3) {
            if (pos + 1 == board.size() || board[pos] != board[pos + 1]) {
                auto tmp = node.top();
                node.pop();
                dfs(board, pos + 1);
                node.push(tmp);
            } else {
                auto tmp = node.top();
                node.pop();

                for (auto[ch, num]: ball) {
                    if (ch == board[pos])
                        continue;
                    for (int j = 1; j <= min(3, num); ++j) {
                        ball[ch] -= j;
                        used += j;

                        if (!node.empty() && node.top().first == ch)
                            node.top().second += j;
                        else
                            node.emplace(ch, j);

                        if (node.top().second >= 3) {
                            auto tmp2 = node.top();
                            node.pop();
                            dfs(board, pos + 1);
                            node.push(tmp2);
                        } else {
                            dfs(board, pos + 1);
                        }

                        if (node.top().second > j)
                            node.top().second -= j;
                        else
                            node.pop();
                        used -= j;
                        ball[ch] += j;
                    }
                }
                node.push(tmp);
            }
        }

        if (ball[board[pos]] >= 1 && (pos + 1 == board.size() || board[pos] != board[pos + 1])) {
            int lim = ball[board[pos]];
            for (int i = 1; i <= min(2, lim); ++i) {
                ball[board[pos]] -= i;
                used += i;
                node.top().second += i;
                if (node.top().second >= 3) {
                    auto tmp = node.top();
                    node.pop();
                    dfs(board, pos + 1);
                    node.push(tmp);
                } else {
                    dfs(board, pos + 1);
                }

                node.top().second -= i;
                used -= i;
                ball[board[pos]] += i;
            }
        }

        if (node.top().second < 3 || (node.top().second == 3 && pos + 1 < board.size() && board[pos] == board[pos + 1]))
            dfs(board, pos + 1);

        if (node.top().second == 1)
            node.pop();
        else
            --node.top().second;
    }
};
