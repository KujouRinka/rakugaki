//
// Created by KujouRinka on 2021/3/28.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// uva10763
int CompoundWord() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
    vector<string> Dict;
    string Str;
    while (cin >> Str)
        Dict.push_back(Str);

    for (auto &i : Dict) {
        for (int j = 0; j < i.size(); j++) {
            string FrontStr = i.substr(0, j);
            string BackStr = i.substr(j);

            if (binary_search(Dict.begin(), Dict.end(), FrontStr) &&
                binary_search(Dict.begin(), Dict.end(), BackStr)) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
