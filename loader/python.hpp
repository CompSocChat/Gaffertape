#include "loader.hpp"
#include <boost/python.hpp>

namespace loader {
  class PythonLoader : public Loader {
    /// Loads a module
    Module * load(std::string path) = 0;
  };

  class PythonModule : public Module {
    friend PythonLoader;
  protected:
    boost::python::object func;
  public:
    std::string run(std::string argument);
  };
}
