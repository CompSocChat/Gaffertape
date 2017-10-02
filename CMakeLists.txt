cmake_minimum_required(VERSION 3.0)
project(gaffertape)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
link_directories(${PYTHON_LIBRARY_DIRS})

SET(Boost_USE_STATIC_RUNTIME OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS OFF)

find_package(Boost REQUIRED COMPONENTS system python)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

file(GLOB load_source ${PROJECT_SOURCE_DIR}/loader/*.cpp)
add_library(gaffertape-load ${load_source})

file(GLOB webserver_source ${PROJECT_SOURCE_DIR}/webserver/*.cpp)
add_library(gaffertape-webserver ${webserver_source})

add_executable(gaffertape main.cpp)

target_link_libraries(gaffertape gaffertape-webserver gaffertape-load ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})
