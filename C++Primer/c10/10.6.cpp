//
// Created by KujouRinka on 2021/3/30.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> v{4, 5, 2, 3, 9, 6, 8};
    fill_n(v.begin(), v.size(), 0);
    return 0;
}
