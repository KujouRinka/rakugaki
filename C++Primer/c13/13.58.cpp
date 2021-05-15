#include <iostream>
#include <vector>
#include <algorithm>

class Foo {
    
public:
    
    Foo sorted() &&;

    Foo sorted() const &;

private:
    
    std::vector<int> data;
};

Foo Foo::sorted() && {
    std::cout << "rvalue reference ver" << std::endl;
    std::sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const & {
    std::cout << "lvalue reference ver" << std::endl;
    Foo ret(*this);
    return Foo(*this).sorted();
    // return ret.sorted(); bad
}

int main() {
    Foo f;
    f.sorted();
    return 0;
}
