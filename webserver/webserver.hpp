#include <boost/asio.hpp>
using namespace boost::asio;

#include "../common.hpp"

namespace webserver {
  class Client {
  public:
    USER_ID name;
    Client(ip::tcp::iostream * stream);
  private:
    ip::tcp::iostream * _stream;
  };


  class Server {
  private:
    ip::tcp::acceptor socket;
  public:
    Client * accept();
  };

}
