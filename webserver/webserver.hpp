#include <boost/asio.hpp>
#include <string>

#include "../common.hpp"

namespace webserver {
  enum RequestType { Get, Post };

  class Server;

  class Request {
    friend Server;
  private:
    boost::asio::ip::tcp::iostream * stream;
  public:
    RequestType type;
    std::string path;
    std::string Version;
    void respond(std::string response);
  };


  class Server {
  private:
    boost::asio::ip::tcp::acceptor * socket;
    boost::asio::io_service * service;
  public:
    Request * receive();
    USER_ID name;
    Server(USER_ID * name, boost::asio::ip::tcp::endpoint ep);
  };

}
