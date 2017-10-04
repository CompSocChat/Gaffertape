#ifndef GAFFERTAPE_LOADER_DYLIB_H
#define GAFFERTAPE_LOADER_DYLIB_H

#ifdef _MSC_VER
  #define GAFFERTAPE_C(arg) __declspec(dllexport) char * gaffertape_c(char * arg)
#elif defined(__GNUC__)
  #define GAFFERTAPE_C(arg) __attribute__((visibility("default"))) char * gaffertape_c(char * arg)
#else
  #error GAFFERTAPE DYLIB PLATFORM NOT SUPPORTED
#endif

struct ModuleArgC {
  /// An optional string field specifying the next Module that this should be forwarded to
  char * forward;
  /// The payload of the ModuleArg
  char * data;
}

#endif
