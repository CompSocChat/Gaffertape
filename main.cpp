#include <iostream>
#include <string>

#include "webserver/webserver.hpp"

using namespace std;
using namespace webserver;
using namespace boost::asio;
using namespace boost::asio::ip;

int main(int argc, char ** argv) {
  cout << "Bound to 127.0.0.1:6989" << endl;
  USER_ID name;
  Server * s = new Server(&name, tcp::endpoint(address_v4::loopback(), 6989));
  Request * c = s->receive();

  return 0;
}
