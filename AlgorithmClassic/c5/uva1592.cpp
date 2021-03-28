//
// Created by KujouRinka on 2021/3/28.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// uva 1592
namespace uva1592 {
    const int ROW = 10005;
    const int COLUMN = 15;
    map<string, int> StrMap;
    vector<string> StrCache;
    map<int, map<int, int>> ResFinder;

    int ID(string Record) {
        int Index;
        if (StrMap.count(Record))
            return StrMap[Record];
        StrCache.push_back(Record);
        return StrMap[Record] = StrCache.size() - 1;
    }

    int Database() {
        int n, m;
        while (cin >> n >> m) {
            map<string, int> EM;
            vector<string> EV;
            StrMap.swap(EM);
            StrCache.swap(EV);
            vector<int> DataTable[ROW];
            string str;
            char ch = getchar();

            for (int i = 0; i < n; i++) {
                for (;;) {
                    ch = getchar();
                    if (ch == '\n' || ch == '\r') {
                        if (!str.empty()) DataTable[i].push_back(ID(str));
                        str.clear();
                        break;
                    }
                    if (ch != ',') str += ch;
                    else {
                        DataTable[i].push_back(ID(str));
                        str.clear();
                    }
                }
            }


            for (int i = 0; i < m; i++) {
                for (int j = i + 1; j < m; j++) {
                    map<int, map<int, int>> Empty;
                    ResFinder.swap(Empty);
                    for (int k = 0; k < n; k++) {
                        int ThisKey = DataTable[k][i];
                        int ThisValue = DataTable[k][j];
                        if (ResFinder.count(ThisKey)) {
                            if (ResFinder[ThisKey].count(ThisValue)) {
                                cout << "NO" << endl;
                                cout << ResFinder[ThisKey][ThisValue] + 1 << " " << k + 1 << endl;
                                cout << i + 1 << " " << j + 1 << endl;
                                goto Finish;
                            } else {
                                ResFinder[ThisKey][ThisValue] = k;
                            }
                        } else {
                            ResFinder[ThisKey][ThisValue] = k;
                        }
                    }
                }
            }
            cout << "YES" << endl;
            Finish:;
        }
        return 0;
    }
}
