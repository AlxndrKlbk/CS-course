#include <cstdlib>

#include <boost/bind.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;


class Session
{
private:
    tcp::socket mSocket;
    enum {max_length = 1024};
    char mData[max_length];

public:
    Session(boost::asio::io_context& io_service):
        mSocket(io_service) {}

    tcp::socket& socket() { return mSocket; }

    void start() {
        mSocket.async_read_some(
            boost::asio::buffer(mData, max_length),
            boost::bind(&Session::handle_read,
                        this,
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));
    }

    void handle_read(const boost::system::error_code& error,
                     size_t bytes_transferred) {
        if (!error) {
            boost::asio::async_write(mSocket,
                                     boost::asio::buffer(mData, bytes_transferred),
                                     boost::bind(&Session::handle_write,
                                                 this,
                                                 boost::asio::placeholders::error));
        } else {
            delete this;
        }
    }

    void handle_write(const boost::system::error_code& error) {
        if (!error) {
            mSocket.async_read_some(
                boost::asio::buffer(mData, max_length),
                boost::bind(&Session::handle_read,
                            this,
                            boost::asio::placeholders::error,
                            boost::asio::placeholders::bytes_transferred));
        } else {
            delete this;
        }
    }
};

class Server
{
private:
    boost::asio::io_context& mIoService;
    tcp::acceptor mAcceptor;

public:
    Server(boost::asio::io_context& service,
           short port) :
        mIoService(service) ,
        mAcceptor(service, tcp::endpoint(tcp::v4(), port))
    {
        Session* newSession = new Session(mIoService);
        mAcceptor.async_accept(newSession->socket(),
                               boost::bind(&Server::handle_accept,
                                           this,
                                           newSession,
                                           boost::asio::placeholders::error));
    }

    void handle_accept(Session* newSession,
                       const boost::system::error_code& error)
    {
        if (!error)
        {
            newSession->start();
            newSession = new Session(mIoService);
            mAcceptor.async_accept(newSession->socket(),
                                   boost::bind(&Server::handle_accept,
                                               this,
                                               newSession,
                                               boost::asio::placeholders::error));
        } else {
            delete newSession;
        }
    }
};

int main(int argc, char** argv) {
    boost::asio::io_context ioService;

    Server srv(ioService, atoi(argv[1]));
    ioService.run();

    return 0;
}
