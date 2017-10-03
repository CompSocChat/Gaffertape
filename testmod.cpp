#include "loader/all.hpp"
#include <string>
#include <iostream>

GAFFERTAPE(arg) {
  std::cout << "RECEIVED \"" << arg << "\" from gaffertape" << std::endl;
  return arg;
}
