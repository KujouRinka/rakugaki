#include <iostream>

namespace NS {
    class Quote;
}
void display(const NS::Quote &);

namespace NS {
    class Quote {
        friend void display(const Quote &);
    };
    void display(const Quote &) {
        std::cout << "display in" << std::endl;
    }
}

void display(const NS::Quote &) {
    std::cout << "display out" << std::endl;
}

class Bulk_item : public NS::Quote {
};

int main() {
    Bulk_item book1;
    ::display(book1);
    NS::display(book1);
    return 0;
}
