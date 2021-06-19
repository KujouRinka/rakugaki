#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string pattern(R"(^(\d{5})((-)?(\d{4}))?)");
    std::regex r(pattern);
    std::smatch result;

    std::string s;
    while (std::getline(std::cin, s)) {
        for (std::sregex_iterator it(s.begin(), s.end(), r), end;
             it != end; ++it) {
            if ((*it)[2].matched)
                std::cout << it->format("$1-$4") << std::endl;
            else
                std::cout << it->str() << std::endl;
        }
    }
    return 0;
}
