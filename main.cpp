#include <iostream>
#include <string>

#include "webserver/webserver.hpp"

using namespace std;
using namespace webserver;
using namespace boost::asio;
using namespace boost::asio::ip;

int main(int argc, char ** argv) {
  cout << "hi" << endl;
  Server * s = new Server(tcp::endpoint(address_v4::loopback(), 6989));
  Client * c = s->accept();
  return 0;
}
