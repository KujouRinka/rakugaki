#include <iostream>

template<typename T, std::size_t N>
constexpr std::size_t arr_size(const T (&arr)[N]) {
    return N;
}

int main() {
    int a[6] = {0, 2, 8, 4, 6, 10};
    std::string vs[3] = {"Hello", "world", "!"};

    std::cout << arr_size(a) << std::endl;
    std::cout << arr_size(vs) << std::endl;
    return 0;
}
