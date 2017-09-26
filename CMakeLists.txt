cmake_minimum_required(VERSION 3.0)
project(gaffertape)
set(Boost_USE_MULTITHREADED ON)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

file(GLOB webserver_source ${PROJECT_SOURCE_DIR}/webserver/*.cpp)

add_library(gaffertape-webserver SHARED ${webserver_source})
target_link_libraries(gaffertape-webserver ${Boost_LIBRARIES})

add_executable(gaffertape main.cpp)
target_link_libraries(gaffertape ${Boost_LIBRARIES} gaffertape-webserver)
