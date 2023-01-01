#include <boost/asio.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Wrong parameter\n"
                  << "Example usage ./client 127.0.0.1 1234 hello" << std::endl;
        return -1;
    } else {
        std::cout << "Client Started!" << std::endl;
    }

    auto const address = boost::asio::ip::make_address(argv[1]);
    auto const port = std::atoi(argv[2]);
    std::string msg = argv[3];

    msg = msg + '\n';

    boost::asio::io_service io_service;

    // socket creation
    boost::asio::ip::tcp::socket socket(io_service);

    // connection
    boost::system::error_code ec;
    socket.connect(boost::asio::ip::tcp::endpoint(address, port), ec);

    if (ec) {
        std::cout << "Socket Failed connection: " << ec.message() << std::endl;
        return 1;
    }
    boost::system::error_code error;
    // Getting response from server
    boost::asio::streambuf receive_buffer;

    // request/message from client
    // const string msg = "Hello from Client!\n";
    boost::asio::write(socket, boost::asio::buffer(msg), error);
    if (error) {
        std::cout << "Send failed: " << error.message() << std::endl;
    }

    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);

    if (error && error != boost::asio::error::eof) {
        std::cout << "Receive failed: " << error.message() << std::endl;
    } else {
        const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        std::cout << data << std::endl;
    }

    return 0;
}