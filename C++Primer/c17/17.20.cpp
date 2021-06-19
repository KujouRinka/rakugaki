#include <iostream>
#include <string>
#include <regex>

bool valid(const std::smatch &m) {
    if (m.empty())
        return false;
    if (m[1].matched)
        return m[3].matched;
    else
        return m[3].matched == 0;
}

int main() {
    std::string pattern(R"(^(\()?(\d{3})(\))?[-\. ]?(\d{3})[-\. ]?(\d{4})$)");
    std::regex r(pattern);
    std::smatch result;

    std::string phones[4]{
            "(777)-333-6666",
            "7773336666",
            "777\\333\\6666",
            "(777-333-6666"
    };
    for (const auto &i : phones) {
        std::regex_match(i, result, r);
        std::cout << (valid(result) ? "" : "in")
                  << std::string("valid number: ")
                  << i << std::endl;
    }
    return 0;
}
