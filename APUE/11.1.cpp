#include <iostream>
#include <pthread.h>
#include <cstring>

using namespace std;

struct Data {
    Data() : length(0), buf(nullptr) {}
    Data(const char *s) {
        length = strlen(s);
        this->buf = new char[length + 1];
        strcpy(buf, s);
    }
    ~Data() { delete buf; }
    size_t length;
    char *buf;
};

void *threadFunction(void *arg) {
    auto data = static_cast<struct Data *>(arg);
    cout << "thread: " << data->buf << " " << data->length << endl;

    auto *new_data = new Data("hello from thread");
    return new_data;
}

int main() {
    pthread_t t1;

    struct Data data("hello from main thread");
    pthread_create(&t1, nullptr, threadFunction, &data);

    struct Data *thread_data;
    pthread_join(t1, reinterpret_cast<void **>(&thread_data));
    cout << "main thread: " << thread_data->buf << " " << thread_data->length << endl;
    delete thread_data;
    return 0;
}
