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
    boost::asio::ip::tcp::acceptor acceptor_(io_service, boost::asio::ip::tcp::endpoint(address, port));

    while (true) {
        boost::asio::ip::tcp::socket socket_(io_service);  // socket creation
        acceptor_.accept(socket_);                         // waiting for connection

        std::cout << "I have a new client :)" << std::endl;

        // Send hello to client
        std::string hello_msg = "Hello new client!\n";

        boost::system::error_code error_msg;
        // Write operation
        boost::asio::write(socket_, boost::asio::buffer(hello_msg), error_msg);
        if (error_msg) {
            std::cout << error_msg.message() << std::endl;
            return 1;
        }

        // Read operation
        boost::asio::streambuf buf;
        boost::asio::read_until(socket_, buf, "\n", error_msg);

        if (error_msg) {
            std::cout << error_msg.message() << std::endl;
            return 1;
        }

        std::string data = boost::asio::buffer_cast<const char *>(buf.data());
        std::cout << data << std::endl;
    }
    return 0;
}