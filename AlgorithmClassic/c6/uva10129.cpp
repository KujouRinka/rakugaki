#include <iostream>
#include <array>
#include <vector>

using namespace std;

void visitedFunc(vector<bool> &visited, array<array<int, 26>, 26> &G, int node) {
    visited[node] = false;
    for (int i = 0; i < 26; ++i) {
        if (G[node][i] && visited[i])
            visitedFunc(visited, G, i);
    }
}

int main() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
    array<int, 26> t{};
    t.fill(0);
    int groups;
    cin >> groups;
    while (groups--) {
        int wordsNum;
        vector<bool> visited(26, false);
        array<array<int, 26>, 26> G{};
        array<int, 26> in{};
        array<int, 26> out{};
        G.fill(t);
        in.fill(0);
        out.fill(0);

        cin >> wordsNum;
        int head, tail;
        while (wordsNum--) {
            string word;
            cin >> word;
            head = word[0] - 'a';
            tail = word[word.size() - 1] - 'a';
            ++G[head][tail];
            ++G[tail][head];
            ++in[tail];
            ++out[head];
            visited[head] = visited[tail] = true;
        }

        visitedFunc(visited, G, head);

        auto f = [&visited, &in, &out]() -> bool {
            int diffIn = 0;
            int diffOut = 0;
            bool flag1 = true;
            bool flag2 = true;
            for (int i = 0; i < 26; ++i) {
                if (visited[i])
                    return false;
                if (in[i] != out[i]) {
                    if (flag1 && in[i] - out[i] == 1) {
                        ++diffIn;
                        flag1 = false;
                    } else if (flag2 && in[i] - out[i] == -1) {
                        ++diffOut;
                        flag2 = false;
                    } else {
                        return false;
                    }
                }

            }
            return (diffIn == 1 && diffOut == 1) || (diffIn == 0 && diffOut == 0);
        };
        if (f())
            cout << "Ordering is possible." << endl;
        else
            cout << "The door cannot be opened." << endl;
    }
    return 0;
}
