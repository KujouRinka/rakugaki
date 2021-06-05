#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <algorithm>

template<typename T>
class Vec;

template<typename T>
inline void swap(Vec<T> &lhs, Vec<T> &rhs);

template<typename T>
class Vec {
    friend void swap<T>(Vec<T> &lhs, Vec<T> &rhs);
public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    inline Vec(std::initializer_list<T> il);
    Vec(const T &s);
    Vec(const Vec &rhs);
    Vec(Vec &&s) noexcept;
    ~Vec();

    Vec &operator=(const Vec &rhs);
    Vec &operator=(Vec &&rhs) noexcept;
    Vec &operator=(std::initializer_list<T> il);
    inline T &operator[](const size_t &index);
    inline const T &operator[](const size_t &index) const;

    void push_back(const T &s);
    void push_back(T &&s);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    void reserve(size_t n) { if (n > capacity()) reallocate(n); }
    inline void resize(size_t n);
    inline void resize(size_t n, const T &s);
    T *begin() const { return elements; }
    T *end() const { return first_free; }

private:

    static std::allocator<T> alloc;
    static std::pair<T *, T *> alloc_n_copy
            (const T *b, const T *e);

    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    void free();
    void reallocate();
    inline void reallocate(size_t n);

    T *elements;  // point to first element
    T *first_free;    // point to first free element
    T *cap;   // point behind-last
};

template<typename T>
inline
Vec<T>::Vec(std::initializer_list<T> il) {
    auto newData = alloc_n_copy(il.begin(), il.end());
    elements = newData.first;
    first_free = newData.second;
    cap = first_free;
}

template<typename T>
Vec<T>::Vec(const T &s) : Vec() {
    push_back(s);
}

template<typename T>
Vec<T>::Vec(const Vec &rhs) {
    auto newData = alloc_n_copy(rhs.begin(), rhs.end());
    elements = newData.first;
    first_free = newData.second;
    cap = first_free;
}

template<typename T>
Vec<T>::Vec(Vec &&s) noexcept:
        elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
}

template<typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs) {
    auto newData = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newData.first;
    first_free = newData.second;
    cap = first_free;
    return *this;
}

template<typename T>
Vec<T> &Vec<T>::operator=(Vec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

template<typename T>
Vec<T> &Vec<T>::operator=(std::initializer_list<T> il) {
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = data.second;
    cap = first_free;
    return *this;
}

template<typename T>
inline
T &Vec<T>::operator[](const size_t &index) {
    return elements[index];
}

template<typename T>
inline
const T &Vec<T>::operator[](const size_t &index) const {
    return elements[index];
}

template<typename T>
Vec<T>::~Vec() {
    free();
}

template<typename T>
void Vec<T>::push_back(const T &s) {
    chk_n_alloc();  // ensure enough space
    alloc.construct(first_free++, s);
}

template<typename T>
void Vec<T>::push_back(T &&s) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

template<typename T>
inline
void Vec<T>::resize(size_t n) {
    resize(n, "");
}

template<typename T>
inline
void Vec<T>::resize(size_t n, const T &s) {
    if (n > size()) {
        while (n != size())
            push_back(s);
    } else if (n < size()) {
        while (n != size())
            alloc.destroy(--first_free);
    }

}

template<typename T>
std::allocator<T> Vec<T>::alloc;

template<typename T>
std::pair<T *, T *>
Vec<T>::alloc_n_copy(const T *b, const T *e) {
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

template<typename T>
void Vec<T>::free() {
    if (elements) {
        std::for_each(begin(), end(), [](T &each) {
            alloc.destroy(&each);
        });
        alloc.deallocate(elements, cap - elements);
    }
}

template<typename T>
void Vec<T>::reallocate() {
    auto newCap = size() ? size() * 2 : 1;
    reallocate(newCap);
}

template<typename T>
inline
void Vec<T>::reallocate(size_t n) {
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

template<typename T>
inline
void swap(Vec<T> &lhs, Vec<T> &rhs) {
    using std::swap;
    swap(lhs.elements, rhs.elements);
    swap(lhs.first_free, rhs.first_free);
    swap(lhs.cap, rhs.cap);
}

int main() {
    Vec<std::string> s("hello world");
    std::cout << s[0];
    return 0;
}
