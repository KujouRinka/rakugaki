#include <iostream>

class Base {

public:

    virtual void f() {
        std::cout << "f in Base" << std::endl;
    }

    virtual void g() {
        std::cout << "g in Base" << std::endl;
    }

};

class Sub1 : public Base {

public:

    virtual void f() override {
        std::cout << "f in Sub1" << std::endl;
    }

    void g() override {
        std::cout << "g in Sub1" << std::endl;
    }

};

class Sub2 : public Sub1 {

public:

    void f() override {
        std::cout << "f in Sub2" << std::endl;
    }

    void g() override {
        std::cout << "g in Sub2" << std::endl;
    }

};

void call(Base &b) {
    b.f();
    b.g();
    std::cout << std::endl;
}

int main() {
    Base b;
    Sub1 s1;
    Sub2 s2;
    call(b);
    call(s1);
    call(s2);
    return 0;
}
