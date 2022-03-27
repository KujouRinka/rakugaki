#include <iostream>
#include <asio.hpp>
#include <memory>
#include <streambuf>
// #include <boost/bind.hpp>
// #include <boost/asio.hpp>

using namespace std;
using namespace asio;

using sock_ptr = shared_ptr<ip::tcp::socket>;

io_context ctx;
ip::tcp::acceptor listener(ctx, ip::tcp::endpoint(ip::address::from_string("127.0.0.1"), 8888));

class TCPConn : public enable_shared_from_this<TCPConn> {
    static constexpr size_t BUF_SIZE = 1024;
public:
    TCPConn(ip::tcp::socket &&sock) : _my_sock(std::move(sock)), _read_buffer(BUF_SIZE, 0) {}
    ~TCPConn() { _my_sock.close(); }

    void to_read() {
        fill(_read_buffer.begin(), _read_buffer.end(), 0);
        _my_sock.async_read_some(
                buffer(_read_buffer),
                [capture = shared_from_this()](const error_code err, size_t sz) {
                    capture->on_read(err, sz);
                }
        );
    }

    void on_read(const error_code err, size_t sz) {
        if (err) {
            // cout << "disconnected" << endl;
            return;
        }
        auto it = _read_buffer.find('\n');
        it = (it == std::string::npos ? sz : it);
        _real_read_buffer.append(_read_buffer.c_str(), it);
        if (it == _read_buffer.size()) {
            // no '\n'
            to_read();
        } else {
            _real_read_buffer += '\n';
            _write_buffer = std::move(_real_read_buffer);
            _real_read_buffer.clear();
            to_write();
        }
    }

    void to_write() {
        _my_sock.async_write_some(
                buffer(_write_buffer),
                [capture = shared_from_this()](const error_code err, size_t sz) {
                    capture->on_write(err, sz);
                }
        );
    }

    void on_write(const error_code err, size_t sz) {
        // if not write fully, call to_write again
        // supposing has written fully
        _write_buffer.clear();
        to_read();
    }

private:
    ip::tcp::socket _my_sock;
    string _read_buffer;
    string _real_read_buffer;
    string _write_buffer;
};


void to_listen() {
    sock_ptr sp(new ip::tcp::socket(ctx));
    listener.async_accept(*sp, [sp](const error_code err) {
        std::make_shared<TCPConn>(std::move(*sp))->to_read();
        to_listen();
    });
}

int main() {
    to_listen();
    ctx.run();
    return 0;
}
