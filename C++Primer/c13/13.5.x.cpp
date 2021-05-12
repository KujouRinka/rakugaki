// trying to reproduce vector without using template

#include <iostream>
#include <string>
#include <memory>
#include <utility>

class StrVec {

public:

    StrVec() :
            elements(nullptr), first_free(nullptr), cap(nullptr) {}

    StrVec(const StrVec &rhs);

    StrVec &operator=(const StrVec &rhs);

    ~StrVec();

    void push_back(const std::string &s);

    size_t size() const { return first_free - elements; }

    size_t capacity() const { return cap - elements; };

    std::string *begin() const { return elements; }

    std::string *end() const { return first_free; }

private:

    static std::allocator<std::string> alloc;

    void chk_n_alloc() { if (size() == capacity()) reallocate(); }

    std::pair<std::string *, std::string *> alloc_n_copy
            (const std::string *b, const std::string *e);

    void free();

    void reallocate();

    std::string *elements;  // point to first element
    std::string *first_free;    // point to first free element
    std::string *cap;   // point behind-last
};

StrVec::StrVec(const StrVec &rhs) {

}

StrVec &StrVec::operator=(const StrVec &rhs) {

}

StrVec::~StrVec() {

}

void StrVec::push_back(const std::string &s) {
    chk_n_alloc();  // ensure enough space
    alloc.construct(first_free++, s);
}

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate() {

}
