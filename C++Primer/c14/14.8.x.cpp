#include <iostream>
#include <string>

class PrintString {

public:

    PrintString(std::ostream &o = std::cout, char c = ' ') :
            os(o), sep(c) {}

    void operator()(const std::string &s) const { os << s << sep; }

private:

    std::ostream &os;
    char sep;

};

int main() {
    PrintString printer;
    printer("hello world");
    PrintString errors(std::cerr, '\n');
    errors("some error occurs.");
    return 0;
}
