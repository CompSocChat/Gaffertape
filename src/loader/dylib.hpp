#pragma once

#include "loader.hpp"

#include <string>

#include <boost/dll.hpp>
#include <boost/functional.hpp>

/// A macro that can be use to define the gaffertape function:
/// `GAFFERTAPE(argument_name) { /* ... */ }`
#define GAFFERTAPE(arg) extern "C" BOOST_SYMBOL_EXPORT std::string gaffertape(std::string arg)
#define GAFFERTAPE_C(arg) extern "C" BOOST_SYMBOL_EXPORT char * gaffertape_c(char * arg)

namespace loader {
  /// Loads a dso or a dll, and runs std::string gaffertape(std::string) or char * gaffertape(char *)
  class DyLibLoader : public Loader {
  public:
    /// Loads a module
    Module * load(std::string path);
    /// A simple constructor for the loader
    DyLibLoader(std::string extension) : Loader(extension) {}
  };

  /// A dso or a dll
  class DyLibModule : public Module {
    friend DyLibLoader;
  private:
    /// The function, or wrapper around, the gaffertape function
    std::function<std::string(const std::string)> func;
  public:
    /// Executes the gaffertape function
    std::string run(const std::string argument);
  };
}
REG_LOADER(new loader::DyLibLoader("so"))
REG_LOADER(new loader::DyLibLoader("dll"))
