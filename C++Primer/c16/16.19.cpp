#include <iostream>
#include <vector>
#include <string>
#include <list>

// code in the reference answer cannot fit the 
// list and other containers, so I wrote mine.
template<typename C>
void printContainer(C &c) {
    auto it = c.begin();
    auto i = typename C::size_type(0);
    for (; i != c.size(); ++i, ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> sV{"hello", "world", "!"};
    std::string s = "example";
    std::list<int> ll = {1, 1, 4, 5, 1, 4};
    printContainer(sV);
    printContainer(s);
    printContainer(ll);
    return 0;
}
