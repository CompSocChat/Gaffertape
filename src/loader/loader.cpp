#include "loader.hpp"

#include <string>
#include <iostream>
#include <map>
using namespace std;

namespace loader {
  map<std::string, Loader*> * LOADER_MAP = 0;// ;
  void Loader::reg(Loader* loader) {
    if (!LOADER_MAP) { LOADER_MAP = new map<std::string, Loader*>(); }
    LOADER_MAP->insert_or_assign(loader->extension, loader);
  }
  void Loader::unreg(const std::string extension) {
    LOADER_MAP->erase(extension);
  }
  Loader * Loader::get(const std::string extension) {
    return LOADER_MAP->at(extension);
  }
  Module * Loader::exec(const std::string path) {
    // 1. Tries to work out the extension
    std::string extension = path.substr(path.find_last_of('.') + 1);
    // 2. Attempts to get the correct Loader
    Loader * loader = get(extension);
    // 3. Attempts to load the module
    return loader->load(path);
  }
}
