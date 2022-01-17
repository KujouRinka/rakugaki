#include <iostream>
#include <array>
#include <string>
#include <memory>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>

using namespace std;
using namespace boost::asio;

std::string makeDaytimeString() {
    time_t now = time(nullptr);
    return ctime(&now);
}

void worker(ip::tcp::socket *sp) {
    string message = makeDaytimeString();
    sp->write_some(buffer(message));
}

void startTimeServer() {
    try {
        io_context ctx;
        ip::tcp::acceptor acceptor(ctx, ip::tcp::endpoint(ip::tcp::v4(), 13));

        while (true) {
            ip::tcp::socket socket(ctx);
            acceptor.accept(socket);
            cout << "recv a conn from: " << socket.remote_endpoint().address().to_string() << endl;
            thread t(std::bind(&worker, &socket));
            t.join();
        }

    } catch (exception &e) {
        cout << e.what() << endl;
    }
}

class tcp_connection {
public:
    typedef shared_ptr<tcp_connection> pointer;

    static pointer create(io_context &ctx) {
        return pointer(new tcp_connection(ctx));
    }

    ip::tcp::socket &socket() {
        return m_socket;
    }

    void start() {
        m_message = makeDaytimeString();
        m_socket.async_write_some(
                buffer(m_message),
                std::bind(&tcp_connection::handler_write, this,
                          std::placeholders::_1, std::placeholders::_2)
        );
    }

private:
    ip::tcp::socket m_socket;
    string m_message;

    tcp_connection(io_context &ctx)
            : m_socket(ip::tcp::socket(ctx)) {
    }

    void handler_write(const boost::system::error_code &e, size_t written) {
        cout << written << " bytes written" << endl;
    }
};

class tcp_server {
public:
    tcp_server(io_context &ctx)
            : m_ctx(ctx), m_acceptor(ctx, ip::tcp::endpoint(ip::tcp::v4(), 13)) {
        start_accept();
    }

    void start_accept() {
        tcp_connection::pointer new_conn = tcp_connection::create(m_ctx);
        m_acceptor.async_accept(
                new_conn->socket(),
                std::bind(&tcp_server::handle_accept, this, new_conn, std::placeholders::_1)
        );
    }

    void handle_accept(const tcp_connection::pointer conn, const boost::system::error_code &error) {
        if (!error) {
            conn->start();
        }
        start_accept();
    }

private:
    io_context &m_ctx;
    ip::tcp::acceptor m_acceptor;
};


void startAsyncServer() {
    try {
        io_context ctx;
        tcp_server server(ctx);
        ctx.run();
    } catch (exception &e) {
        cout << e.what() << endl;
    }
}

int main(int argc, char **argv) {
    thread t(startAsyncServer);
    t.detach();
    sleep(2);

    try {
        if (argc != 2) {
            std::cout << "Usage: client <host>" << std::endl;
            return 1;
        }
        io_context ctx;
        ip::tcp::resolver resolver(ctx);
        ip::tcp::resolver::results_type endpoints = resolver.resolve(argv[1], "daytime");

        ip::tcp::socket socket(ctx);
        boost::asio::connect(socket, endpoints);

        while (true) {
            array<char, 1024> buf;
            boost::system::error_code error;

            size_t len = socket.read_some(buffer(buf), error);
            if (error == error::eof)
                break;
            else if (error)
                throw boost::system::system_error(error);

            cout.write(buf.data(), len);
        }

    } catch (std::exception &e) {
        cout << e.what() << endl;
    }
    return 0;
}

