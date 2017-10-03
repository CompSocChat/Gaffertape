#include "dylib.hpp"

#include <iostream>
using namespace std;

using namespace boost::dll;


namespace loader {
  Module * DyLibLoader::load(string path) {
    DyLibModule * ret = new DyLibModule();
    try {
      ret->func = import<string(const string)>(path, "gaffertape");
    } catch (boost::system::system_error& e) {
      cout << "char **" << endl;
      function<char*(const char*)> c_f = import<char*(const char*)>(path, "gaffertape");
      ret->func = function([=](string s) { return string(c_f(s.c_str())); });
    }
    return ret;
  }

  std::string DyLibModule::run(string argument) {
    return func(argument);
  }
}
