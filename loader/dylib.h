#ifdef _MSC_VER
  #define GAFFERTAPE_C(arg) __declspec(dllexport) char * gaffertape_c(char * arg)
#elif defined(__GNUC__)
  #define GAFFERTAPE_C(arg) __attribute__((visibility("default"))) char * gaffertape_c(char * arg)
#else
  #error GAFFERTAPE DYLIB PLATFORM NOT SUPPORTED
#endif
