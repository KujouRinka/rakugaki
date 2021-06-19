#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string pattern(R"(^(\d{5})((-)?(\d{4}))?)");
    std::regex r(pattern);
    std::smatch result;

    std::string phones[4]{
            "555555555",
            "55555",
            "55555-5555",
            "55555-"
    };
    for (const auto &i : phones) {
        int st = std::regex_match(i, result, r);
        std::cout << (st ? "" : "in")
                  << std::string("valid: ") << i
                  << "\tpart1: " << result.str(1)
                  << "\tpart2: " << result.str(2)
                  << std::endl;
    }
    return 0;
}
