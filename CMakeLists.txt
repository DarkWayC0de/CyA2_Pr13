cmake_minimum_required(VERSION 3.15)
project(pr13)

set(CMAKE_CXX_STANDARD 14)

add_executable(pr13 src/main.cpp src/sorted_vector_t/sorted_vector_t.h src/sorted_vector_t/sorted_vector_t.cpp)