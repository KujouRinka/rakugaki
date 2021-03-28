//
// Created by KujouRinka on 2021/3/28.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

// uva572
namespace uva572 {
    int piece = 0;
    int maxRow, maxLine;
    char pic[505][505] = {0};

    void explore(int row, int line) {
        if (pic[row][line] != '@')
            return;
        if (row >= maxRow || line >= maxLine || row < 0 || line < 0)
            return;
        pic[row][line] = '*';
        explore(row - 1, line - 1);
        explore(row - 1, line);
        explore(row - 1, line + 1);
        explore(row, line - 1);
        explore(row, line + 1);
        explore(row + 1, line - 1);
        explore(row + 1, line);
        explore(row + 1, line + 1);
    }

    int oliDeposits() {
        freopen("read.in", "r", stdin);
        freopen("write.out", "w", stdout);
        while (cin >> maxRow >> maxLine) {
            //char pic[100][100] = {0};
            if (maxRow == 0 && maxLine == 0)
                return 0;
            memset(pic, 0, sizeof(pic));
            piece = 0;
            for (int i = 0; i < maxRow; ++i)
                scanf("%s", pic[i]);
            for (int i = 0; i < maxRow; ++i)
                for (int j = 0; j < maxLine; ++j) {
                    if (pic[i][j] == '@') {
                        explore(i, j);
                        piece++;
                    }
                }
            cout << piece << endl;
        }
        return 0;
    }
}
