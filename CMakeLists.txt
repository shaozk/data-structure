cmake_minimum_required(VERSION 3.17)
project(data_structure C)

set(CMAKE_C_STANDARD 11)

include_directories(demo/include)

add_executable(SqList demo/SqList.c)
add_executable(MergeList demo/MergeList.c)

