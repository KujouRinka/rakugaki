//
// Created by KujouRinka on 2021/3/30.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool filter(const string &s) {
    return s.size() > 5;
}

int main() {
    vector<string> v{
            "abcdd",
            "adefggaf",
            "as",
            "dse3",
            "saf33f",
    };
    auto endIt = partition(v.begin(), v.end(), filter);
    for (auto it = v.begin(); it != endIt; ++it)
        cout << *it << " ";
    return 0;
}
