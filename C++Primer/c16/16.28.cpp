// implement simple ver of shared_ptr and unique_ptr
#include <iostream>
#include <string>

template<typename T>
class SP {
public:
    SP() : p(nullptr), use(nullptr) {}
    explicit SP(T *pt) : p(pt), use(new std::size_t(1)) {}
    SP(const SP &sp) :
            p(sp.p), use(sp.use) { if (use) ++*use; }
    SP &operator=(const SP &rhs);
    ~SP();

    T operator*() const { return *p; }
    T *operator->() const { return p; }

    bool unique() const { return *use == 1; }
    std::size_t use_count() const { return *use; }
    T *get() const { return p; }
    void swap(SP &sp);

private:
    T *p;
    std::size_t *use;

};

template<typename T>
SP<T>::~SP() {
    if (use && --*use == 0) {
        delete p;
        delete use;
    }
}

template<typename T>
SP<T> &SP<T>::operator=(const SP<T> &rhs) {
    if (rhs.use)
        ++*rhs.use;
    if (use && --*use == 0) {
        delete p;
        delete use;
    }
    p = rhs.p;
    use = rhs.use;
    return *this;
}

template<typename T>
void SP<T>::swap(SP<T> &sp) {
    T *tmp = p;
    p = sp.p;
    sp.p = tmp;
}

template<typename T, class... Args>
SP<T> make_SP(Args &&... args) {
    return SP<T>(new T(std::forward<Args>(args)...));
}


template<typename T>
class UP {
public:
    UP() : p(nullptr) {}
    explicit UP(T *pt) : p(pt) {}
    UP(const UP &) = delete;
    UP &operator=(const UP &) = delete;
    ~UP();

    T operator*() const { return *p; }
    T *operator->() const { return p; }

    T *get() const { return p; }
    T *release();
    void reset(T *pt = nullptr);
    void swap(UP &up);

private:
    T *p;
};

template<typename T>
UP<T>::~UP<T>() {
    if (p)
        delete p;
}

template<typename T>
T *UP<T>::release() {
    T *tp = p;
    p = nullptr;
    return tp;
}

template<typename T>
void UP<T>::reset(T *pt) {
    delete p;
    p = pt;
}

template<typename T>
void UP<T>::swap(UP<T> &up) {
    T *tmp = p;
    p = up.p;
    up.p = tmp;
}

int main() {
    int *p;
    SP<int> sp1(new int(114514)), sp2;
    UP<int> up1(new int(2333));
    sp2 = sp1;
    std::cout << *sp2 << " count: " << sp1.use_count() << " " << sp2.use_count() << std::endl;
    SP<std::string> ssp(new std::string("hello world!"));
    std::cout << ssp->back() << std::endl;
    std::cout << *up1 << " " << reinterpret_cast<unsigned long long>(up1.get());
    return 0;
}
