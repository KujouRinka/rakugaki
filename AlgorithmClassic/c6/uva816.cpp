//
// Created by KujouRinka on 2021/3/28.
//

#include <iostream>
#include <string>
#include <array>
#include <map>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

// uva816
namespace uva816 {
    struct routeNode {
        int x, y;
        char headDir;
        routeNode *tail;

        routeNode(int x, int y, char h, routeNode *p = nullptr) : x(x), y(y), headDir(h), tail(p) {}
    };

    const string direction = "NESW";
    const string head = "FRAL";
    map<char, array<int, 2>> moveMap{
            {'N', {-1, 0}},
            {'E', {0,  1}},
            {'S', {1,  0}},
            {'W', {0,  -1}},
    };

    int endX, endY;
    queue<routeNode *> bfsQ;

    string calcFromTo(const string &cmd) {
        string dirs;
        int fromIndex = direction.find(cmd[0]);
        for (int i = 1; i < cmd.size(); ++i)
            dirs += direction[(fromIndex + head.find(cmd[i])) % 4];
        return dirs;
    }

    void printRes(routeNode *lastNode) {
        stack <array<int, 2>> tmp;
        tmp.push({endX, endY});
        for (; lastNode != nullptr; lastNode = lastNode->tail) {
            tmp.push({lastNode->x, lastNode->y});
        }

        cout << " ";
        int count = 0;
        while (!tmp.empty()) {
            cout << " (" << tmp.top()[0] << "," << tmp.top()[1] << ")";
            ++count;
            tmp.pop();

            if (count % 10 == 0 && !tmp.empty())
                cout << endl << " ";
        }
        cout << endl;
    }

    void bfs(map<char, string> cross[10][10]) {
        map<char, bool> visited[10][10];
        vector < routeNode * > allNode;

        while (!bfsQ.empty()) {
            routeNode *thisNode = bfsQ.front();
            bfsQ.pop();
            int newX, newY;
            int thisX, thisY;

            thisX = thisNode->x;
            thisY = thisNode->y;
            newX = thisX + moveMap[thisNode->headDir][0];
            newY = thisY + moveMap[thisNode->headDir][1];

            if (newX == endX && newY == endY) {
                printRes(thisNode);
                for (auto &i : allNode)
                    delete i;
                return;
            }

            if (newX >= 0 && newY >= 0 && newX < 10 && newY < 10 && !cross[newX][newY].empty()) {
                if (cross[newX][newY].count(thisNode->headDir))
                    for (const auto &newH : cross[newX][newY][thisNode->headDir]) {
                        if (!visited[newX][newY][newH]) {
                            auto *newNode = new routeNode(newX, newY, newH, thisNode);
                            bfsQ.push(newNode);
                            allNode.push_back(newNode);
                            visited[newX][newY][newH] = true;
                        }
                    }
            }
        }
        cout << "  No Solution Possible" << endl;
    }

    void solve(routeNode *node, map<char, string> cross[10][10], const string &name) {
        cout << name << endl;
        bfsQ.push(node);
        bfs(cross);
    }

    int AbbottRevenge() {
        string name;
        while (cin >> name && name != "END") {
            map<char, string> cross[10][10];

            int startX, startY;
            char startDir;
            cin >> startX >> startY >> startDir >> endX >> endY;

            int tagX, tagY;
            while (cin >> tagX && tagX != 0) {
                cin >> tagY;
                string cmd;
                while (cin >> cmd && cmd != "*") {
                    string m(calcFromTo(cmd));
                    for (const auto &i : m)
                        cross[tagX][tagY][cmd[0]] += i;
                }
            }
            routeNode start(startX, startY, startDir);
            solve(&start, cross, name);
        }
        return 0;
    }
}
