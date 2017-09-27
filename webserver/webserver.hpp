#include <boost/asio.hpp>
#include <string>

#include "../common.hpp"

namespace webserver {

  class InvalidRequest : public std::exception {};

  class Server;

  class Request {
    friend Server;
  private:
    boost::asio::ip::tcp::socket * socket;
  public:
    std::string verb;
    std::string path;
    std::string version;
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
