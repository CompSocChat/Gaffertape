#include "loader/dylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char * ret = "Hi from C!";
GAFFERTAPE_C(arg) {
  printf("Received \"%s\" from gaffertape\n", arg);
  char * s = calloc(strlen(ret) + 1, 1);
  strcpy(s, ret);
  return s;
}
