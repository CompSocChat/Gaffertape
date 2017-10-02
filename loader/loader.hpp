#pragma once

#include <boost/python.hpp>
#include <string>
#include <functional>

namespace loader {
  class Loader;
  /// A bass class for modules
  class Module {
  public:
    /// Calls a module
    virtual std::string run(std::string argument) = 0;
    /// The parent that owns this module
    Loader* parent;
    /// The path to the module
    std::string path;
  };
  /// A base class for loading modules
  class Loader {
  public:
    /// Registers a loader
    static void reg(Loader * loader);
    /// Unregisters a loader
    static void unreg(std::string extension);
    /// Attempts to find a module
    /// Will return null if the loader could not be found
    static Loader * get(std::string extension);
    /// Loads a module
    virtual Module * load(std::string path) = 0;
    /// The extension for the loader
    std::string extension;
  };
}
