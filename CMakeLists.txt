cmake_minimum_required(VERSION 3.17)
project(SequentialQuickSort C)

set(CMAKE_C_STANDARD 99)

SET(CMAKE_C_COMPILER mpicc)

SET(GCC_OPTIMIZE_COMPILE_FLAGS "-O0")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_OPTIMIZE_COMPILE_FLAGS}")

add_executable(SequentialQuickSort main.c utils.c utils.h quicksort.c quicksort.h)
