#include <iostream>
#include <string>
#include <functional>

#include "webserver/webserver.hpp"
#include "loader/all.hpp"

using namespace std;

using namespace webserver;
using namespace loader;

using namespace boost::asio;
using namespace boost::asio::ip;

int main(int argc, char ** argv) {
  DyLibLoader v;
  Module * mod = v.load("bin/libtestmod.so");

  cout << endl << "Returned " << mod->run("You smell") << endl;

  cout << "Bound to http://127.0.0.1:6989" << endl;
  USER_ID name;
  Server * s = new Server(&name, tcp::endpoint(address_v4::loopback(), 6989));
  FileGetRequestHandler get("/tmp/files");
  FilePostRequestHandler post("/tmp/files");

  cout << endl;

  while(true) {
    Request * c = s->receive();
    cout << "Verb: '" << c->header.verb << "'" << endl;
    cout << "Path: '" << c->header.path << "'" << endl;
    cout << "Version: '" << c->header.version << "'" << endl;

    if (get.handle(*c)) {
      cout << "Got";
    //} else if (post.handle(*c)) {
    //  cout << "Posted";
    } else {
      cout << "Bad request";
      Response response;
      response.header.code = Bad_Request;
      c->respond(response);
    }
    cout << endl << endl;

  }
  return 0;
}
