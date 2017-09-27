#define RECEIVE_MAX_LEN 65536

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
  //TODO: Implement Server::receive fully
  Request * Server::receive() {

    tcp::socket * client = new tcp::socket(*service);
    socket->accept(*client);
    Request * r = new Request();
    r->socket = client;

    asio::streambuf header_buf(RECEIVE_MAX_LEN);
    read_until(*client, header_buf, "\r\n\r\n");

    istream header(&header_buf);

    header >> r->verb >> r->path >> r->version;

    return r;
  }

  Server::Server(USER_ID * _name, tcp::endpoint ep) {
    memcpy(&name, _name, sizeof(USER_ID));
    service = new io_service();
    socket = new tcp::acceptor(*service, ep);
    socket->listen();
  }

}
