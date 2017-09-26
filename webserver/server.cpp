#include <boost/asio.hpp>
using namespace boost::asio;

#include "webserver.hpp"

namespace webserver {
  Client::Client(ip::tcp::iostream * stream) {
    _stream = stream;
  }

  Client * Server::accept() {
    ip::tcp::iostream stream;
    socket.accept(*stream.rdbuf());
    return new Client(&stream);
  }

}
