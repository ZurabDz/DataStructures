cmake_minimum_required(VERSION 3.1)
project(DataStructures)

find_package(fmt REQUIRED)

set(TESTER ON BOOL "Tester")

# Optional codebase doesn't usase anything from c++17 yet
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR/bin}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${fmt_INCLUDE_DIRS})


if (TESTER)
  add_subdirectory(test)
endif()

add_executable(prog main.cpp)
target_link_libraries(prog fmt::fmt)