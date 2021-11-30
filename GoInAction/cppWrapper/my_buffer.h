#ifndef my_buffer
#define my_buffer

#include <string>

struct MyBuffer {
    std::string *s_;
    MyBuffer(int size) {
        this->s_ = new std::string(size, char('\0'));
    }
    ~MyBuffer() {
        delete this->s_;
    }
    int size() const {
        return this->s_->size();
    }
    char *data() {
        return (char *) this->s_->data();
    }
};

#endif
