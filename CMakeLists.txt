cmake_minimum_required(VERSION 3.25)
project(lab02)

set(CMAKE_CXX_STANDARD 17)

include(cmake/CPM.cmake)

#https://github.com/fmtlib/fmt.git
CPMAddPackage("gh:fmtlib/fmt#10.0.0")

find_package(MPI REQUIRED)

add_executable(Examen_Final main.cpp)

target_link_libraries(Examen_Final fmt::fmt)
