#include "python.hpp"
#include <boost/python.hpp>
#include <iostream>

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
    Py_Initialize();
    object main = import("__main__");
    object dict = main.attr("__dict__");
    str pypath = str(path);
    exec_file(pypath, dict);
    ret->func = dict["gaffertape"];
    return (Module *) ret;
  }
}
