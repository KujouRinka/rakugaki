class FooBar {
public:
    FooBar(int n) : n(n), _which(1) {}

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(_mu);
            _cv.wait(lk, [this] { return _which == 1; });
            printFoo();
            _which = 2;
            _cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(_mu);
            _cv.wait(lk, [this] { return _which == 2; });
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            _which = 1;
            _cv.notify_one();
        }
    }

private:
    int n;
    int _which;
    mutex _mu;
    condition_variable _cv;
};

