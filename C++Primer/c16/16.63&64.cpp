#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

template<typename T>
int occur(vector<T> &vec, const T &t) {
    int ret = 0;

    for (auto i : vec)
        if (i == t)
            ++ret;
    return ret;
}

template<>
int occur(vector<char *> &vec, char *const &v) {
    int ret = 0;

    for (auto i : vec)
        if (!strcmp(i, v))
            ++ret;
    return ret;
}

template<>
int occur(vector<const char *> &vec, const char *const &v) {
    return occur(reinterpret_cast<vector<char *> &>(vec), const_cast<char *const>(v));
}

int main() {
    vector<char *> vec1 = {"hello", "world"};
    char *p2 = "hello";
    vector<const char *> vec2 = {"hello", "world"};
    const char *cp2 = "world";
    cout << occur(vec1, p2) << endl;
    cout << occur(vec2, cp2) << endl;
    return 0;
}
