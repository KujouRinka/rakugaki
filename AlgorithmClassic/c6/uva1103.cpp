//
// Created by KujouRinka on 2021/3/28.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

// uva1103
namespace uva1103 {
    int data[201][201];
    int tmpMap[205][205];
    int row, charNum;

    void makeMap() {    // convert hex to bin
        string tmp;
        for (int i = 0; i < row; ++i) {
            cin >> tmp;
            for (int j = 0; j < charNum; ++j) {
                int n1 = stoi(tmp.substr(j, 1), nullptr, 16);
                for (int k = 0; k < 4; ++k)
                    data[i][4 * j + k] = ((uint32_t) n1 >> (uint32_t) (3 - k)) & 1;
            }
        }
    }

    void make(int i, int j) {
        if (i < 0 || j < 0 || i >= row || j >= charNum * 4)
            return;
        if (data[i][j] == 0)
            return;
        data[i][j] = 0;
        tmpMap[i + 1][j + 1] = 1;
        make(i - 1, j);
        make(i + 1, j);
        make(i, j - 1);
        make(i, j + 1);

    }

    bool makeBlackMap() {
        memset(tmpMap, 0, sizeof(tmpMap));
        for (int i = 0; i < charNum * 4 + 2; ++i)
            for (int j = 0; j < row + 2; ++j) {
                if (data[j][i] == 1) {
                    make(j, i);
                    return true;
                }
            }
        return false;
    }

    void fillWhite(int i, int j) {
        if (i < 0 || j < 0 || i >= row + 2|| j >= charNum * 4 + 2)
            return;
        if (tmpMap[i][j] == 1)
            return;
        tmpMap[i][j] = 1;
        fillWhite(i - 1, j - 1);
        fillWhite(i - 1, j);
        fillWhite(i - 1, j + 1);
        fillWhite(i + 1, j - 1);
        fillWhite(i + 1, j);
        fillWhite(i + 1, j + 1);
        fillWhite(i, j - 1);
        fillWhite(i, j + 1);
    }

    int findWhitePiece() {
        int count = 0;


        for (int i = 0; i < row + 2; ++i)
            for (int j = 0; j < charNum * 4 + 2; ++j) {
                if (tmpMap[i][j] == 0) {
                    fillWhite(i, j);
                    count++;

                }
            }
        return count - 1;
    }

    void solve() {
        vector<char> res;
        while (makeBlackMap()) {

            int p = findWhitePiece();
            char ch;
            switch (p) {
                case 0:
                    ch = 'W';
                    break;
                case 1:
                    ch = 'A';
                    break;
                case 2:
                    ch = 'K';
                    break;
                case 3:
                    ch = 'J';
                    break;
                case 4:
                    ch = 'S';
                    break;
                case 5:
                    ch = 'D';
                    break;
            }
            res.push_back(ch);
        }
        sort(res.begin(), res.end());
        for (const auto &i : res)
            cout << i;
        cout << endl;
    }

    int ancientMsg() {
        int Case = 0;
        while (cin >> row >> charNum && row) {
            makeMap();

            cout << "Case " << ++Case << ": ";
            solve();
        }
        return 0;
    }
}
