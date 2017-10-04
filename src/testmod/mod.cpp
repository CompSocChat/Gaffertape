#include "../loader/all.hpp"
#include <iostream>

GAFFERTAPE(arg) {
  std::cout << "Received \"" << arg << "\" from gaffertape" << std::endl;
  return "Hi from C++!";
}
