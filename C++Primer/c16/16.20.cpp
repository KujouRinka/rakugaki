#include <iostream>
#include <vector>
#include <string>
#include <list>

template<typename C>
void printVector(C &c) {
    for (auto it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> sV{"hello", "world", "!"};
    std::string s = "example";
    std::list<int> ll = {1, 1, 4, 5, 1, 4};
    printVector(sV);
    printVector(s);
    printVector(ll);
    return 0;
}
