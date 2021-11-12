cmake_minimum_required(VERSION 3.20)
project(SequentialQuickSort C)

set(CMAKE_C_STANDARD 99)

add_executable(SequentialQuickSort main.c utils.c utils.h quicksort.c quicksort.h)
