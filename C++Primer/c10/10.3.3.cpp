//
// Created by KujouRinka on 2021/4/2.
//

#include <iostream>
#include <algorithm>

using namespace std;

int upperCounter() {
    int range = 6;
    vector<int> v;
    for (int i = 0; i < 20; ++i)
        v.push_back(i);
    int counter = count_if(v.begin(), v.end(),
                           [&range](int a) -> bool { return a > range; });
    return counter;
}

void reduceEach(int times) {
    int cap;
    auto f = [&cap]() -> bool { return cap == 0 ? false : (--cap, true); };
    while (times--) {
        bool thisValue = f();
        cout << thisValue << " ";
    }
    cout << endl;
}