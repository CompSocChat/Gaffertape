#include "loader.hpp"

using namespace boost::python;
using namespace std;

namespace loader {
  class PythonLoader : publ {

  }
  string call(string i) {
    Py_Initialize();
    object main = import("__main__");
    object globals = main.attr("__dict__");
    Py_Finalize();
  }
}
