// simple tcp socket server example with boost asio
// sudo apt install libboost-dev
// g++ -lpthread -lboost_system server.cpp -o server
#include <boost/asio.hpp>
#include <iostream>

class Server {
   public:
    Server(const std::string ip, const unsigned int port, boost::asio::io_service &io_service) : io_service_(io_service) {
        std::cout << "Server created" << std::endl;
    }

   private:
    boost::asio::io_service &io_service_;
};

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Wrong parameter\n"
                  << "Example usage 127.0.0.1 1234" << std::endl;
        return -1;
    }

    auto const address = boost::asio::ip::make_address(argv[1]);
    auto const port = std::atoi(argv[2]);

    boost::asio::io_service io_service;

    // Listen for new connection
    boost::system::error_code ec;
    boost::asio::ip::tcp::acceptor acceptor_(io_service, boost::asio::ip::tcp::endpoint(address, port));

    boost::asio::ip::tcp::socket socket_(io_service);  // socket creation
    acceptor_.accept(socket_);                         // waiting for connection

    // Read operation
    boost::asio::streambuf buf;
    boost::asio::read_until(socket_, buf, "\n", ec);

    if (ec) {
        std::cout << ec.message() << std::endl;
        return 1;
    }

    std::string data = boost::asio::buffer_cast<const char *>(buf.data());
    std::cout << data << std::endl;

    // Write operation
    boost::asio::write(socket_, boost::asio::buffer(data), ec);
    if (ec) {
        std::cout << ec.message() << std::endl;
        return 1;
    }
    return 0;
}