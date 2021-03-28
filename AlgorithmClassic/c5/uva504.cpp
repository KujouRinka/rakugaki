//
// Created by KujouRinka on 2021/3/28.
//

#include <iostream>
#include <queue>
#include <map>

using namespace std;
// uva540
bool Friend(int MyTeamNum, queue<int> AllQueue) {
    while (!AllQueue.empty()) {
        if (AllQueue.front() == MyTeamNum)
            return true;
        AllQueue.pop();
    }
    return false;
}

int TeamQueueProb() {
    int Times = 0;
    int TeamQuantity, MemberQuantity, MemberTmpNum;
    map<int, int> TeamNum;
    queue<int> AllQueue;
    map<int, queue<int>> TeamQueue;
    while (cin >> TeamQuantity && TeamQuantity) {
        TeamNum.clear();
        TeamQueue.clear();
        queue<int> Empty;
        AllQueue.swap(Empty);

        while (TeamQuantity--) {
            cin >> MemberQuantity;
            for (int i = 0; i < MemberQuantity; i++) {
                cin >> MemberTmpNum;
                TeamNum[MemberTmpNum] = TeamQuantity;
            }
        }

        cout << "Scenario #" << ++Times << endl;
        string Operation;
        int MemberNum;
        while (cin >> Operation) {
            if (Operation[0] == 'D') {
                cout << TeamQueue[AllQueue.front()].front() << endl;
                TeamQueue[AllQueue.front()].pop();
                if (TeamQueue[AllQueue.front()].empty())
                    AllQueue.pop();
            } else if (Operation[0] == 'S')
                break;
            else if (Operation[0] == 'E') {
                cin >> MemberNum;
                int MyTeamNum = TeamNum[MemberNum];
                if (Friend(MyTeamNum, AllQueue))
                    TeamQueue[MyTeamNum].push(MemberNum);
                else {
                    AllQueue.push(MyTeamNum);
                    TeamQueue[MyTeamNum].push(MemberNum);
                }
            } else
                continue;
        }
        cout << endl;
    }
    return 0;
}
