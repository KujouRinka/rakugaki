class Foo {
public:
    Foo() : _run(1) {}

    void first(function<void()> printFirst) {
        unique_lock<mutex> lk(m);
        _cv.wait(lk, [this]() { return _run == 1; });
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        _run = 2;
        _cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lk(m);
        _cv.wait(lk, [this]() { return _run == 2; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        _run = 3;
        _cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lk(m);
        _cv.wait(lk, [this]() { return _run == 3; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        _run = 1;
        _cv.notify_all();
    }

private:
    int _run;
    mutex m;
    condition_variable _cv;
};

