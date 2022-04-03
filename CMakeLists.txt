cmake_minimum_required(VERSION 3.17)
project(cpp_playground)

set(PROJECT_NAME MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS, "-g Wall")
enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

add_executable(main main.cpp)