#include "loader.hpp"
#include <boost/python.hpp>

namespace loader {
  class PythonLoader : public Loader {
  public:
    /// Loads a module
    Module * load(std::string path);
  };

  class PythonModule : public Module {
    friend PythonLoader;
  protected:
    boost::python::object func;
  public:
    std::string run(std::string argument);
  };
}
