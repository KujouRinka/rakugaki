// trying to reproduce vector without using template

#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <algorithm>

class StrVec {

    friend inline void swap(StrVec &lhs, StrVec &rhs);

public:

    StrVec() :
            elements(nullptr), first_free(nullptr), cap(nullptr) {}

    inline StrVec(std::initializer_list<std::string> il);

    StrVec(const char *s);

    StrVec(const std::string &s);

    StrVec(const StrVec &rhs);

    StrVec(StrVec &&s) noexcept;

    StrVec &operator=(const StrVec &rhs);

    StrVec &operator=(StrVec &&rhs) noexcept;

    StrVec &operator=(std::initializer_list<std::string> il);

    inline std::string &operator[](const size_t &index);

    inline const std::string &operator[](const size_t &index) const;

    ~StrVec();

    void push_back(const std::string &s);

    void push_back(std::string &&s);

    size_t size() const { return first_free - elements; }

    size_t capacity() const { return cap - elements; }

    void reserve(size_t n) { if (n > capacity()) reallocate(n); }

    inline void resize(size_t n);

    inline void resize(size_t n, const std::string &s);

    std::string *begin() const { return elements; }

    std::string *end() const { return first_free; }

private:

    static std::allocator<std::string> alloc;

    static std::pair<std::string *, std::string *> alloc_n_copy
            (const std::string *b, const std::string *e);

    void chk_n_alloc() { if (size() == capacity()) reallocate(); }

    void free();

    void reallocate();

    inline void reallocate(size_t n);

    std::string *elements;  // point to first element
    std::string *first_free;    // point to first free element
    std::string *cap;   // point behind-last
};

inline
StrVec::StrVec(std::initializer_list<std::string> il) {
    auto newData = alloc_n_copy(il.begin(), il.end());
    elements = newData.first;
    first_free = newData.second;
    cap = first_free;
}

StrVec::StrVec(const char *s) : StrVec(std::string(s)) {}

StrVec::StrVec(const std::string &s) : StrVec() {
    push_back(s);
}

StrVec::StrVec(const StrVec &rhs) {
    auto newData = alloc_n_copy(rhs.begin(), rhs.end());
    elements = newData.first;
    first_free = newData.second;
    cap = first_free;
}

StrVec::StrVec(StrVec &&s) noexcept:
        elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto newData = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newData.first;
    first_free = newData.second;
    cap = first_free;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

StrVec &StrVec::operator=(std::initializer_list<std::string> il) {
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = data.second;
    cap = first_free;
    return *this;
}

inline
std::string &StrVec::operator[](const size_t &index) {
    return elements[index];
}

inline
const std::string &StrVec::operator[](const size_t &index) const {
    return elements[index];
}

StrVec::~StrVec() {
    std::cout << "free called" << std::endl;
    free();
}

void StrVec::push_back(const std::string &s) {
    chk_n_alloc();  // ensure enough space
    alloc.construct(first_free++, s);
}

void StrVec::push_back(std::string &&s) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

inline
void StrVec::resize(size_t n) {
    resize(n, "");
}

inline
void StrVec::resize(size_t n, const std::string &s) {
    if (n > size()) {
        while (n != size())
            push_back(s);
    } else if (n < size()) {
        while (n != size())
            alloc.destroy(--first_free);
    }

}

std::allocator<std::string> StrVec::alloc;

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

// void StrVec::free() {
//     if (elements) {
//         for (auto p = first_free; p != elements;)
//             alloc.destroy(--p);
//         alloc.deallocate(elements, cap - elements);
//     }
// }

void StrVec::free() {
    if (elements) {
        std::for_each(begin(), end(), [](std::string &each) {
            alloc.destroy(&each);
        });
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate() {
    auto newCap = size() ? size() * 2 : 1;
    reallocate(newCap);
}

inline
void StrVec::reallocate(size_t n) {
    auto newData = alloc.allocate(n);
    auto dest = newData;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newData;
    first_free = dest;
    cap = elements + n;
}

inline
void swap(StrVec &lhs, StrVec &rhs) {
    using std::swap;
    swap(lhs.elements, rhs.elements);
    swap(lhs.first_free, rhs.first_free);
    swap(lhs.cap, rhs.cap);
}
