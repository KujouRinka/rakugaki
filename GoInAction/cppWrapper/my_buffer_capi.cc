#include "my_buffer.h"

extern "C"
{
#include "my_buffer_capi.h"
}

struct MyBuffer_T : MyBuffer {
    MyBuffer_T(int size) : MyBuffer(size) {}
    ~MyBuffer_T() {}
};

MyBuffer_T *NewMyBuffer(int size) {
    auto p = new MyBuffer_T(size);
    return p;
}

void DeleteMyBuffer(MyBuffer_T *p) {
    delete p;
}

char *MyBufferData(MyBuffer_T *p) {
    return p->data();
}

int MyBufferSize(MyBuffer_T *p) {
    return p->size();
}
