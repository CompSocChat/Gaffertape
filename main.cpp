#include <iostream>
#include <string>

#include "webserver/webserver.hpp"

using namespace std;
using namespace webserver;
using namespace boost::asio;
using namespace boost::asio::ip;

int main(int argc, char ** argv) {
  cout << "Bound to http://127.0.0.1:6989" << endl;
  USER_ID name;
  Server * s = new Server(&name, tcp::endpoint(address_v4::loopback(), 6989));

  while(true) {
    Request * c = s->receive();
    cout << "Verb: '" << c->header.verb << "'" << endl;
    cout << "Path: '" << c->header.path << "'" << endl;
    cout << "Version: '" << c->header.version << "'" << endl;

    Response r;
    r.header.code = Ok;
    r.body = "Hello, World!";
    c->respond(&r);
  }
  return 0;
}
