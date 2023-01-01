#include "TCPClient.h"

namespace nexthink {

TCPClient::TCPClient(boost::asio::io_service& io_service) : io_service_(io_service),
                                                            socket_(io_service) {
}

bool TCPClient::connect(const std::string ip, const unsigned int port) {
    bool connected = false;

    boost::system::error_code error_code;

    boost::asio::ip::address address = boost::asio::ip::address::from_string(ip);
    socket_.connect(boost::asio::ip::tcp::endpoint(address, port), error_code);

    if (error_code) {
        std::cout << "Socket Failed connection: " << error_code.message() << std::endl;
    } else {
        std::cout << "Connection established!" << std::endl;
        connected = true;
    }

    return connected;
}

void TCPClient::write() {
    boost::system::error_code error;

    // request/message from client
    const std::string msg = "Version Request\n";
    boost::asio::write(socket, boost::asio::buffer(msg), error);

    if (error) {
        std::cout << "Client Send failed: " << error.message() << std::endl;
    } else {
        std::cout << "Client Sent: " << msg;
    }
}

void TCPClient::read() {
    boost::system::error_code error;
    boost::asio::streambuf receive_buffer;

    boost::asio::read(socket_, receive_buffer, boost::asio::transfer_all(), error);

    if (error && error != boost::asio::error::eof) {
        std::cout << "Client Receive failed: " << error.message() << std::endl;
    } else {
        const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        std::cout << "Client Received: " << data << std::endl;
    }
}

}  // namespace nexthink
