cmake_minimum_required(VERSION 3.17)
project(data_structure C)

set(CMAKE_C_STANDARD 11)

include_directories(demo/include)

add_executable(SqList demo/SqList.c demo/utils/print.h)
add_executable(LinkList demo/LinkList.c demo/include/LinkList.h demo/utils/print.h)
add_executable(MergeList demo/MergeList.c demo/utils/print.h)
add_executable(ReverseList demo/ReverseList.c demo/utils/print.h)


