cmake_minimum_required(VERSION 3.0)
project(gaffertape)
set(Boost_USE_MULTITHREADED ON)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

find_package(Boost REQUIRED COMPONENTS system python)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
link_directories(${PYTHON_LIBRARY_DIRS})

file(GLOB python_source ${PROJECT_SOURCE_DIR}/python/*.cpp)
add_library(gaffertape-python ${python_source})

file(GLOB webserver_source ${PROJECT_SOURCE_DIR}/webserver/*.cpp)
add_library(gaffertape-webserver ${webserver_source})

add_executable(gaffertape main.cpp)

target_link_libraries(gaffertape PRIVATE ${Boost_LIBRARIES} gaffertape-webserver gaffertape-python PRIVATE ${PYTHON_LIBRARIES})
