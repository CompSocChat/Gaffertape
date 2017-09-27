#include <boost/asio.hpp>
using namespace boost::asio;
using namespace boost::asio::ip;

#include "webserver.hpp"

namespace webserver {
  Client::Client(tcp::iostream * stream) : stream(stream) {}

  Client * Server::accept() {
    tcp::iostream stream;
    socket->accept(*stream.rdbuf());
    return new Client(&stream);
  }

  Server::Server(tcp::endpoint ep) {
    service = new io_service();
    socket = new tcp::acceptor(*service, ep);
    socket->listen();
  }

}
