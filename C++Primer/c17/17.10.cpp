#include <iostream>
#include <bitset>

int main() {
    unsigned int set[] = {1, 2, 3, 5, 8, 13, 21};
    unsigned int bp = 0;
    for (auto i : set)
        bp |= 1UL << i;
    std::bitset<32> bv(bp);
    std::cout << bv << std::endl;

    std::bitset<32> bv1;
    for (auto i : set)
        bv1.set(i);
    std::cout << bv1 << std::endl;
    return 0;
}
