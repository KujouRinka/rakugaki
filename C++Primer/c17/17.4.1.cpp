#include <iostream>
#include <random>

unsigned int rand_int(long seed = -1, long min = 1, long max = 0) {
    static std::uniform_int_distribution<unsigned> u(0, 9999);
    static std::default_random_engine e;

    if (seed >= 0)
        e.seed(seed);
    if (min <= max)
        u = std::uniform_int_distribution<unsigned>(min, max);
    return u(e);
}

int main() {
    for (int i = 0; i < 10; ++i) {
        std::cout << rand_int() << " ";
    }
    std::cout << std::endl;
    return 0;
}
