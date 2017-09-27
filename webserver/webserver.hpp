#include <boost/asio.hpp>

#include "../common.hpp"

namespace webserver {
  class Client {
  private:
    boost::asio::ip::tcp::iostream * stream;
  public:
    USER_ID name;
    Client(boost::asio::ip::tcp::iostream * stream);
  };


  class Server {
  private:
    boost::asio::ip::tcp::acceptor * socket;
    boost::asio::io_service * service;
  public:
    Client * accept();
    Server(boost::asio::ip::tcp::endpoint ep);
  };

}
