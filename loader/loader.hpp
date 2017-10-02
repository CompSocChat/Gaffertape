#pragma once

#include <boost/python.hpp>
#include <string>
#include <functional>

namespace loader {
  class Loader;

  class Module {
  public:
    // Calls a module
    virtual std::string run(std::string argument) = 0;
    Loader* parent;
  }
  /// A base class for loading modules
  class Loader {
  public:
    // Registers a loader
    static void reg(Loader * loader);
    // Unregisters a loader
    static void unreg(std::string extension);
    // Will return null if the loader could not be found
    static Loader * get(std::string extension);
    // Loads a module
    virtual load(std::string path) = 0;
    // The extension for a loader
    virtual static std::string extension;
  }
}
