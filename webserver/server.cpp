
#include <boost/tokenizer.hpp>
using namespace boost;

#include <boost/asio.hpp>
using namespace boost::asio;
using namespace boost::asio::ip;

#include <boost/algorithm/string.hpp>
using namespace boost::algorithm;


using namespace std;

#include "webserver.hpp"

namespace webserver {
  Request * Server::receive() {
    tcp::iostream stream;
    socket->accept(*stream.rdbuf());
    Request * r = new Request();
    r->stream = &stream;
    throw "Not done yet!";
    /*
    streambuf b;
    size_t header_rn = s::find("\r\n")
    header = s.substr(0, header_rn - 2);

    size_t path_s = header::find()
    path
    to_lower(s.substr(0, s::find(' ')- 1));
    return r;
    */
  }

  Server::Server(USER_ID * _name, tcp::endpoint ep) {
    memcpy(&name, _name, sizeof(USER_ID));
    service = new io_service();
    socket = new tcp::acceptor(*service, ep);
    socket->listen();
  }

}
