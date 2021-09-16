struct node;
class Trie;

struct node {
public:
    node() : children(26), isEnd(false) {}
    vector<node *> children;
    bool isEnd;
};

class Trie {
public:
    Trie() : head(new node) {}

    void insert(const string &word) {
        struct node *thisNode = head;
        for (char ch : word) {
            int index = getInd(ch);
            if (thisNode->children[index] == nullptr)
                thisNode->children[index] = new node;
            thisNode = thisNode->children[index];
        }
        thisNode->isEnd = true;
    }

    bool search(const string &word) {
        struct node *thisNode = head;
        for (char ch : word) {
            int index = getInd(ch);
            if (thisNode->children[index] == nullptr)
                return false;
            thisNode = thisNode->children[index];
        }
        return thisNode->isEnd;
    }

    bool startsWith(const string &prefix) {
        struct node *thisNode = head;
        for (char ch : prefix) {
            int index = getInd(ch);
            if (thisNode->children[index] == nullptr)
                return false;
            thisNode = thisNode->children[index];
        }
        return true;
    }


    struct node *head;
    static inline int getInd(char ch) {
        return ch - 'a';
    }
};

class Solution {
public:
    Solution() : trie() {}
    vector<string> findWords(vector<vector<char>> &board, const vector<string> &words) {
        set<string> dataSet(words.begin(), words.end());
        for (auto &i : dataSet)
            trie.insert(i);
        run(board, dataSet);

        
        return {result.rbegin(), result.rend()};
    }

private:
    Trie trie;
    set<string> result;

    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void run(vector<vector<char>> &board, const set<string> &dataSet) {
        for (int i = 0; i < board[0].size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                char s[1000] = {0};
                vector<char> ts;
                dfs(board, i, j, trie.head, ts);
            }
        }
    }

    void dfs(vector<vector<char>> &board, int x, int y, node *root, vector<char> &ts) {
        char ch = board[y][x];

        node *group = root->children[ch - 'a'];
        if (group == nullptr) {
            return;
        }

        ts.push_back(ch);
        if (group->isEnd)
            result.insert(string(ts.begin(), ts.end()));
        board[y][x] = '#';

        for (int i = 0; i < 4; ++i) {
            int nextX = x + dirs[i][0];
            int nextY = y + dirs[i][1];
            if (nextX >= 0 && nextY >= 0 && nextX < board[0].size() && nextY < board.size()) {
                char nextCh = board[nextY][nextX];
                if (nextCh != '#')
                    dfs(board, nextX, nextY, group, ts);
            }
        }
        board[y][x] = ch;
        ts.pop_back();
    }
};
