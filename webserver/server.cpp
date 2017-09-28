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

  const char * const delim = "\r\n";
  const char * const hdelim = "\r\n\r\n";

  std::ostream & operator<<(std::ostream & s, ResponseCode rc) {
    switch(rc) {
      Continue: s << "Continue"; break;
      Ok: s << "Ok"; break;
      Bad_Request: s << "Bad Request"; break;
      Not_Found: s << "Not Found"; break;
    }
    return s;
  }

  string RequestHeader::build() const {
    stringstream ss;
    ss << verb << " " << path << " " << version;
    for (auto const& i : headers) {
      ss << delim << i.name << ": " << i.value;
    }
    ss << hdelim;
    return ss.str();
  }

  string ResponseHeader::build() const {
    stringstream ss;
    ss << version << " " << (int) code << code;
    for (auto const& i : headers) {
      ss << delim << i.name << ": " << i.value;
    }
    ss << hdelim;
    return ss.str();
  }

  std::string Response::build() const {
    return header.build() + body;
  }

  void Request::respond(const Response * r) {
    write(*socket, buffer(r->build()));
    socket->close();
  }

  Request::~Request() {
    delete(socket);
  }

  Server::Server(USER_ID * _name, tcp::endpoint ep) {
    memcpy(&name, _name, sizeof(USER_ID));
    service = new io_service();
    socket = new tcp::acceptor(*service, ep);
    socket->listen();
  }

  //TODO: Implement Server::receive properly
  Request * Server::receive() {

    tcp::socket * client = new tcp::socket(*service);
    socket->accept(*client);
    Request * r = new Request();
    r->socket = client;

    asio::streambuf header_buf(RECEIVE_MAX_LEN);
    read_until(*client, header_buf, "\r\n\r\n");

    istream rec_header(&header_buf);

    rec_header >> r->header.verb >> r->header.path >> r->header.version;

    return r;
  }

  Server::~Server() {
    delete(socket);
    delete(service);
  }

}
