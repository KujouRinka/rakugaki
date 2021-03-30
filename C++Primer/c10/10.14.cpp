//
// Created by KujouRinka on 2021/3/30.
//

#include <iostream>


int main() {
    auto f = [](int a, int b) -> int { return a + b; };
    std::cout << f(4, 5) << std::endl;
    return 0;
}
