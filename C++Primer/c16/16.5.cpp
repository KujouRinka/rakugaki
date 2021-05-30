#include <iostream>
#include <string>

template<typename T, unsigned int N>
void print(const T (&arr)[N]) {
    for (const auto &i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    int a[6] = {0, 2, 4, 6, 8, 10};
    std::string vs[3] = {"Hello", "world", "!"};

    print(a);
    print(vs);

    return 0;
}
