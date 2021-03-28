//
// Created by KujouRinka on 2021/3/28.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>

using namespace std;

// uva210
void ConcurrencySimulator() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);

    struct ins {
        int ID;
        int method;
        vector<string> argument;
    };
    typedef queue<ins> Thread;
    int n, each = 1;
    cin >> n;
    int n_t = n;
    while (n--) {

        int threadNum;
        int clock[5];
        int creation;
        cin >> threadNum;
        for (auto &i : clock)
            cin >> i;
        cin >> creation;
        getchar();

        int Count = 0;
        deque<Thread> threads;
        while (threadNum--) {   // start: 输入所有程序
            string instruction;
            Thread tmpTread;
            Count++;
            while (getline(cin, instruction)) {
                ins tmpIns;
                int tPos;
                if ((tPos = instruction.find('=')) != string::npos) {
                    tmpIns.method = 0;
                    tmpIns.argument.push_back(instruction.substr(0, tPos - 1));
                    tmpIns.argument.push_back(instruction.substr(tPos + 2));
                } else if (instruction.find("print") != string::npos) {
                    tmpIns.method = 1;
                    tmpIns.argument.push_back(instruction.substr(instruction.find(' ') + 1));
                } else if (instruction == "lock") {
                    tmpIns.method = 2;
                } else if (instruction == "unlock") {
                    tmpIns.method = 3;
                } else {
                    tmpIns.method = 4;
                    tmpTread.push(tmpIns);
                    break;
                }
                tmpIns.ID = Count;
                tmpTread.push(tmpIns);
            }
            threads.push_back(tmpTread);
        }   // end: 输入所有程序

        queue<Thread> blockQueue;
        map<string, string> values;
        bool locked = false;
        while (!threads.empty()) {
            Thread task = threads.front();
            threads.pop_front();
            int nowCreation = creation;
            while (nowCreation > 0) {
                ins nowIns = task.front();
                int method = nowIns.method;
                if (method == 0) {   // 赋值
                    values[nowIns.argument[0]] = nowIns.argument[1];
                    task.pop();
                } else if (method == 1) {    // 输出
                    cout << nowIns.ID << ": ";
                    if (values[nowIns.argument[0]] != "")
                        cout << values[nowIns.argument[0]] << endl;
                    else
                        cout << 0 << endl;
                    task.pop();
                } else if (method == 2) {    // 锁
                    if (locked) {
                        blockQueue.push(task);
                        goto there;
                    }
                    locked = true;
                    task.pop();
                } else if (method == 3) {    // 解锁
                    locked = false;
                    task.pop();
                    if (!blockQueue.empty()) {
                        threads.push_front(blockQueue.front());
                        blockQueue.pop();
                    }
                } else if (method == 4) {    // 结束
                    goto there;
                }
                nowCreation -= clock[method];
            }
            threads.push_back(task);
            there:;
        }
        if (each++ != n_t)
            cout << endl;
    }
}

void matrixChainMultiple() {
    int n;
    cin >> n;
    map<char, vector<int>> matrix;
    for (int i = 0; i < n; i++) {
        char name;
        int dimensionX, dimensionY;
        cin >> name >> dimensionX >> dimensionY;
        matrix[name] = {dimensionX, dimensionY};
    }
    getchar();

    stack<char> matrixName;
    int ch;
    int base = 0;
    char allocName = 'a';
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            cout << base << endl;
            stack<char> empty;
            matrixName.swap(empty);
            base = 0;
            allocName = 'a';
        } else if (ch == ')') {
            int t1, t2, t3, t4;
            t1 = matrix[matrixName.top()][1];
            t2 = matrix[matrixName.top()][0];
            matrixName.pop();
            t3 = matrix[matrixName.top()][1];
            t4 = matrix[matrixName.top()][0];
            matrixName.pop();
            if (t3 != t2) {
                cout << "error" << endl;
                while ((ch = getchar()) != '\n');
                stack<char> empty;
                matrixName.swap(empty);
                base = 0;
            } else {
                base += (t1 * t2 * t4);
                int newDimensionX = t4;
                int newDimensionY = t1;
                char newName = allocName++;
                matrixName.push(newName);
                matrix[newName] = {newDimensionX, newDimensionY};
            }
        } else if (ch != '(')
            matrixName.push(ch);
    }
}
