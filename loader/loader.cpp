#include "loader.hpp"

#include <string>
#include <map>
using namespace std;

namespace loader {
  static map<std::string, Loader*> LOADER_MAP;
  void Loader::reg(Loader* loader) {
    LOADER_MAP.insert_or_assign(loader->extension, loader);
  }
  void Loader::unreg(std::string extension) {
    LOADER_MAP.erase(extension);
  }
}
