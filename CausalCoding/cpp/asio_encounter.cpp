#include <iostream>
#include <functional>
#include <thread>

#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace boost;

void print(asio::steady_timer *t, int *count) {
    if (*count < 5) {
        cout << *count << endl;
        t->expires_after(asio::chrono::seconds(1));
        ++(*count);
        t->async_wait(bind(print, t, count));
    }
}

class Printer {
public:
    Printer(asio::io_context &ctx)
            : strand_(asio::make_strand(ctx)),
              t1(ctx, asio::chrono::seconds(1)),
              t2(ctx, asio::chrono::seconds(1)),
              count(0) {
        t1.async_wait(asio::bind_executor(strand_, std::bind(&Printer::print1, this)));
        t2.async_wait(asio::bind_executor(strand_, std::bind(&Printer::print2, this)));
    }
    ~Printer() {
        cout << "final count is: " << count << endl;
    }

private:
    asio::strand<asio::io_context::executor_type> strand_;
    asio::steady_timer t1;
    asio::steady_timer t2;
    int count;

    void print1() {
        if (count < 10) {
            cout << "Timer1: " << count << endl;
            t1.expires_after(asio::chrono::seconds(1));
            ++count;
            t1.async_wait(asio::bind_executor(strand_, std::bind(&Printer::print1, this)));
        }
    }

    void print2() {
        if (count < 10) {
            cout << "Timer2: " << count << endl;
            t2.expires_after(asio::chrono::seconds(1));
            ++count;
            t2.async_wait(asio::bind_executor(strand_, std::bind(&Printer::print2, this)));
        }
    }
};

int main() {
    asio::io_context ctx;
    Printer p(ctx);
    thread t(boost::bind(&asio::io_context::run, &ctx));
    ctx.run();
    t.join();
}

