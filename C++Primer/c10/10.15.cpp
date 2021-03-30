//
// Created by KujouRinka on 2021/3/30.
//

#include <iostream>

int main() {
    int a = 4;
    auto f = [a](int b) -> int { return a + b; };
    std::cout << f(4) << std::endl;
    return 0;
}
