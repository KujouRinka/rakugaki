#include <iostream>

using namespace std;

template<typename T1, typename T2>
auto f(T1 t1, T2 t2) -> decltype(t1 + t2) {
    return t1 + t2;
}
