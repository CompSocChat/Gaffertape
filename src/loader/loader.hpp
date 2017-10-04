#pragma once
#include <iostream>

#include <boost/python.hpp>
#include <string>
#include <functional>

#define __REG_LOADER_CONCAT(counter) __reg_loader_  ## counter
#define __REG_LOADER_NAME(counter) __REG_LOADER_CONCAT(counter)
#define REG_LOADER(LOADER) const loader::internal::RegLoader __REG_LOADER_NAME(__COUNTER__)(LOADER);

namespace loader {
  class Loader;
  /// A bass class for modules
  class Module {
  public:
    /// Registers a module
    static void reg(Loader* loader);
    /// Unregisters a module
    static void unreg(const std::string id);
    /// Attempts to find a module
    static Module * get(const std::string extension);
    /// Calls a module
    virtual std::string run(std::string argument) = 0;
    /// The parent that owns this module
    Loader* parent;
    /// The path to the module
    std::string path;
    /// A name for the module, with no newlines `'\n'`
    std::string id;
  };
  /// A base class for loading modules
  class Loader {
  public:
    /// Registers a loader
    static void reg(Loader* loader);
    /// Unregisters a loader
    static void unreg(const std::string extension);
    /// Attempts to find a loader
    static Loader * get(const std::string extension);
    /// Big super function of death. Does the following
    /// 1. Tries to work out the extension
    /// 2. Attempts to get the correct Loader
    /// 3. Attempts to load the module
    static Module * exec(const std::string path);
    /// Loads a module
    virtual Module * load(const std::string path) = 0;
    /// The extension for the loader
    std::string extension;
    /// The constructor for the base class
    Loader(std::string extension) : extension(extension) {}
  };
  namespace internal {
    class RegLoader {
    public:
      RegLoader(loader::Loader* loader) {
        loader::Loader::reg(loader);
      }
    };
  }
}
