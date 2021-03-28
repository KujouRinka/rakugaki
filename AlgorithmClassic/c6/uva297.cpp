//
// Created by KujouRinka on 2021/3/28.
//

#include <iostream>
#include <cstring>

using namespace std;

// uva297
namespace uva297 {
    int area;
    int pic[32][32];
    char s1[10005], s2[10005];
    int Index = 0;

    void draw(const char *s, int xBorder, int yBorder, int b) {
        int op = s[Index++];
        if (op == 'p') {
            draw(s, xBorder, yBorder, b / 2);
            draw(s, xBorder + b / 2, yBorder, b / 2);
            draw(s, xBorder, yBorder + b / 2, b / 2);
            draw(s, xBorder + b / 2, yBorder + b / 2, b / 2);
        }
        if (op == 'f') {
            for (int i = xBorder; i < xBorder + b; ++i)
                for (int j = yBorder; j < yBorder + b; ++j)
                    if (!pic[i][j]) {
                        pic[i][j] = 1;
                        area++;
                    }
        }
    }

    void process(const char *s1, const char *s2) {
        Index = 0;
        draw(s1, 0, 0, 32);
        Index = 0;
        draw(s2, 0, 0, 32);
    }

    int quadTrees() {
        freopen("read.in", "r", stdin);
        freopen("write.out", "w", stdout);
        int n;
        cin >> n;
        while (n--) {
            area = 0;
            memset(pic, 0, sizeof(pic));
            scanf("%s%s", s1, s2);
            process(s1, s2);

            cout << "There are " << area << " black pixels." << endl;
        }
        return 0;
    }
}
