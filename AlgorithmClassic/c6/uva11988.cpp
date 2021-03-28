//
// Created by KujouRinka on 2021/3/28.
//

// uva11988

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void insert(vector<char> &linkList, vector<int> &next, int &cursor, char value) {
    linkList.push_back(value);
    next.push_back(next[cursor]);
    next[cursor] = linkList.size() - 1;
    cursor = next[cursor];
}

int brokenKeyboard() {
    string input;

    while (getline(cin, input)) {
        vector<char> linkList = {0};
        vector<int> next = {0};
        int cursor = 0;
        int last = 0;

        for (const auto &i : input) {
            if (i == '[') {
                cursor = 0;
            } else if (i == ']') {
                cursor = last;
            } else {
                insert(linkList, next, cursor, i);
                if (next[cursor] == 0)
                    last = cursor;
            }
        }
        for (int i = 0; next[i];) {
            i = next[i];
            cout << linkList[i];
        }
        cout << endl;
    }
    return 0;
}
