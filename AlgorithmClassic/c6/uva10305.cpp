//
// Created by KujouRinka on 2021/4/3.
//

#include <iostream>
#include <vector>

using namespace std;

bool bfs(vector<vector<int>> &pointedTo, vector<int> &bePointedNum, vector<int> &sorted) {
    int visited = 0;
    vector<int> head;
    vector<bool> numVisited(pointedTo.size(), false);

    while (visited != pointedTo.size() - 1) {
        head.clear();

        for (int i = 1; i < bePointedNum.size(); ++i) {
            if (bePointedNum[i] == 0 && numVisited[i] == false) {
                head.push_back(i);
                numVisited[i] = true;
            }
        }

        if (head.empty() && visited != pointedTo.size() - 1)
            return false;

        for (const auto &i : head) {
            for (const auto &j : pointedTo[i])
                bePointedNum[j]--;
            sorted.push_back(i);
            visited++;
        }
    }

    return true;
}

int orderingTasks() {
    int taskQuan, relation;
    while (cin >> taskQuan >> relation && taskQuan != 0) {
        vector<vector<int>> pointTo(taskQuan + 1);
        vector<int> bePointedNum(taskQuan + 1);
        vector<int> sorted;

        while (relation--) {
            int pointer, pointed;
            cin >> pointer >> pointed;
            pointTo[pointer].push_back(pointed);
            bePointedNum[pointed]++;
        }

        bool f = bfs(pointTo, bePointedNum, sorted);
        if (f)
            for (const int &i : sorted)
                cout << i << " ";
        else
            cout << "no solu";
        cout << endl;
    }
    return 0;
}