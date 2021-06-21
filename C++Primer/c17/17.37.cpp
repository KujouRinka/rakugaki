#include <iostream>
#include <fstream>

int main() {
    std::ifstream in("read.in");

    char text[50];
    while (!in.eof()) {
        in.getline(text, 30);
        std::cout << text << std::endl;
        std::cout << in.gcount() << std::endl;
        if (!in.good())
            if (in.gcount() == 29)
                in.clear();
            else
                break;
    }
    return 0;
}
