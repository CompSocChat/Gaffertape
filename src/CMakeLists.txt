cmake_minimum_required(VERSION 3.0)
project(gaffertape)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)

find_package(PythonInterp EXACT 3 REQUIRED)

find_package(PythonLibs EXACT 3 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
link_directories(${PYTHON_LIBRARY_DIRS})

SET(Boost_USE_STATIC_RUNTIME OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS OFF)

if(UNIX)
  set(libdl dl)
  set(pythboost python-py${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR})
else()
  set(pythboost python${PYTHON_VERSION_MAJOR})
endif()
find_package(Boost REQUIRED COMPONENTS system filesystem ${pythboost})
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

file(GLOB load_source ${PROJECT_SOURCE_DIR}/loader/*.cpp)
add_library(gaffertape-load ${load_source})

file(GLOB webserver_source ${PROJECT_SOURCE_DIR}/webserver/*.cpp)
add_library(gaffertape-webserver ${webserver_source})

add_executable(gaffertape ${PROJECT_SOURCE_DIR}/main.cpp)

set(links gaffertape-webserver gaffertape-load ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} ${libdl})

target_link_libraries(gaffertape ${links})

# Test stuff
##enable_testing()
##
##add_executable(testmod ${PROJECT_SOURCE_DIR}/main.cpp)
##add_dependencies(testmod ${PROJECT_SOURCE_DIR}/testmod/* ${links})
##add_test(testmod testmod)
