#include "python.hpp"
#include <boost/python.hpp>

using namespace boost::python;
using namespace std;

namespace loader {
  string PythonModule::run(string i) {
    return extract<std::string>(func(i));
  }
  Module * PythonLoader::load(string path) {
    PythonModule * ret = new PythonModule();
    ret->parent = this;
    ret->path = path;
    object main_module = import("__main__");
    exec_file(str(path), main_module);
    ret->func = main_module.attr("__dict__").attr("gaffertape");
    return (Module *) ret;
  }
}
