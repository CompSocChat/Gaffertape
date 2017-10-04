#pragma once

#include "loader.hpp"
#include <boost/python.hpp>


namespace loader {
  /// Loads a python file and runs def gaffertape(arg)
  class PythonLoader : public Loader {
  public:
    /// Loads a python file
    Module * load(std::string path);
    PythonLoader(std::string extension) : Loader(extension) {}
  };

  class PythonModule : public Module {
    friend PythonLoader;
  public:
    /// The gaffertape function
    boost::python::object func;
  public:
    /// Executes the gaffertape function
    std::string run(std::string argument);
  };
}

REG_LOADER(new loader::PythonLoader(".py"))
