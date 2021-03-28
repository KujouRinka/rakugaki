//
// Created by KujouRinka on 2021/3/28.
//

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

// uva12504
namespace uva12504 {
    void printEach(char ch, set<string> &R) {
        if (!R.empty()) {
            cout << ch;
            auto it = R.cbegin();
            do {
                if (it != R.begin())
                    cout << ",";
                cout << *it;
                it++;
            } while (it != R.end());
            cout << endl;
        }
    }

    int UpdatingDict() {
        freopen("read.in", "r", stdin);
        freopen("write.out", "w", stdout);
        int groups;
        cin >> groups;
        getchar();  // 吸收第一个回车
        while (groups--) {
            map<string, string> dict[2];
            int status = 0;

            for (int i = 0; i < 2; i++) {   // start: 读入两个字典
                int ch;
                string tmpKey, tmpValue;
                while ((ch = getchar())) {
                    if (ch == '{')
                        continue;

                    if (ch == ':') {
                        status = 1;
                        continue;
                    } else if (ch == ',' || ch == '}') {
                        if (!tmpValue.empty()) {
                            dict[i][tmpKey] = tmpValue;
                            tmpKey.clear();
                            tmpValue.clear();
                            status = 0;
                        }
                        if (ch == '}') {
                            getchar();  // 吸收回车符
                            break;
                        }
                        continue;
                    }

                    if (status == 0) {
                        tmpKey += char(ch);
                    } else {
                        tmpValue += char(ch);
                    }
                }
            }   // end: 读入两个字典

            set<string> add;
            set<string> minus;
            set<string> update;
            for (auto &i : dict[0]) {
                if (!dict[1].count(i.first))
                    minus.insert(i.first);
                else if (i.second != dict[1][i.first])
                    update.insert(i.first);
            }

            for (auto &i : dict[1]) {
                if (!dict[0].count(i.first))
                    add.insert(i.first);
            }
            if (add.empty() && minus.empty() && update.empty())
                cout << "No changes" << endl;
            else {
                printEach('+', add);
                printEach('-', minus);
                printEach('*', update);
            }
            cout << endl;
        }

        return 0;
    }
}
