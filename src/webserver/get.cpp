#include "webserver.hpp"
#include <fstream>
#include <iostream>

using namespace std;

namespace webserver {
  bool FileGetRequestHandler::handle(Request& req) {
    if (req.header.verb != "GET" || !resolve(req.header.path)) { return false; }
    ifstream file(req.header.path, ifstream::binary);
    stringstream body;
    Response r;
    if (!file) {
      r.header.code = Not_Found;
    } else if (!(body << file.rdbuf())) {
      r.header.code = Internal_Server_Error;
    } else {
      r.header.code = Ok;
      r.body = body.str();
    }
    req.respond(r);
    return true;
  }
}
