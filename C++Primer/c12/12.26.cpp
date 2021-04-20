#include <iostream>
#include <string>
#include <memory>

int main() {
    std::allocator<std::string> alloc;
    auto const sp = alloc.allocate(10);
    auto sq = sp;
    std::string s;
    while (std::cin >> s && sq != sp + 10) {
        alloc.construct(sq++, s);
    }
    const size_t size = sq - sp;
    while (sq != sp)
        alloc.destroy(--sq);
    alloc.deallocate(sp, 10);
    return 0;
}
