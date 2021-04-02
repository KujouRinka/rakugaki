//
// Created by KujouRinka on 2021/4/2.
//

#include <iostream>

using namespace std;

int someLambda() {
    int cap = 1;
    auto f1 = [](int a, int b) -> int { return a + b};
    auto f2 = [cap](int a) -> int { return cap + a };

    return 0;
}