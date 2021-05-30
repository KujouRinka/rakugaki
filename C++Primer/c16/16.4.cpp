#include <iostream>
#include <string>
#include <vector>
#include <list>

template<typename Iter, typename T>
Iter find(Iter begin, Iter end, const T &v) {
    for (; begin != end && *begin != v; ++begin)
        ;
    return begin;
}

int main() {
    std::vector<int> vi = {0, 2, 4, 6, 8, 10};
    std::list<std::string> ls = {"Hello", "World", "!"};
    auto it = find(vi.begin(), vi.end(), 6);
    if (it == vi.end())
        std::cout << "cannot find 6" << std::endl;
    else
        std::cout << "find 6 at position " << it - vi.begin() << std::endl;

    auto it2 = find(ls.begin(), ls.end(), "mom");
    if (it2 == ls.end())
        std::cout << "cannot find mom" << std::endl;
    else
        std::cout << "found mom" << std::endl;

    return 0;
}
