#include <iostream>
#include <algorithm>

template<typename T, std::size_t N>
T *begin(const T (&arr)[N]) {
    return const_cast<T *>(arr);
}

template<typename T, std::size_t N>
T *end(const T (&arr)[N]) {
    return const_cast<T *>(arr + N);
}

template<typename T, unsigned int N>
void print(const T (&arr)[N]) {
    for (const auto &i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    int a[6] = {0, 2, 8, 4, 6, 10};
    std::string vs[3] = {"Hello", "world", "!"};

    std::sort(begin(a), end(a));
    std::sort(begin(vs), end(vs));

    print(a);
    print(vs);
    return 0;
}
