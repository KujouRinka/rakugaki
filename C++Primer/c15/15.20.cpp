// comments are error code.
#include <iostream>

class Base {
public:
    int pub_mem;
protected:
    int prot_mem;
private:
    int priv_mem;
};

class Pub_Derv : public Base {
public:
    int f() { return prot_mem; }
    // int g() { return priv_mem; }
    Base b = *this;
};

class Priv_Derv : private Base {
public:
    int f1() const { return prot_mem; }
    Base b = *this;
};

class Derived_from_Public : public Pub_Derv {
public:
    int use_base() { return prot_mem; }
    Base b = *this;
};

class Derived_from_Private : public Priv_Derv {
public:
    // int use_base() { return prot_mem; }
    // Base b = *this;
};

void outF(Base &br) {
    
}

int main() {
    Base b;
    Pub_Derv d1;
    Priv_Derv d2;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    outF(b);
    outF(d1);
    // outF(d2);
    outF(dd1);
    // outF(dd2);
    b = d1;
    // b = d2;
    b = dd1;
    // b = dd2;
    Base *bp = &d1;
    // bp = &d2;
    bp = &dd1;
    // bp = &dd2;

    return 0;
}
