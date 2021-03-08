cmake_minimum_required(VERSION 3.17)
project(data_structure C)

set(CMAKE_C_STANDARD 11)

include_directories(demo/include)

add_executable(sq_list demo/sq_list.c demo/utils/print.h)
add_executable(link_list demo/link_list.c demo/include/link_list.h demo/utils/print.h)
add_executable(merge_list demo/merge_list.c demo/utils/print.h demo/include/link_list.h)
add_executable(reverse_list demo/reverse_list.c demo/utils/print.h)
add_executable(sq_stack demo/sq_stack.c demo/include/sq_stack.h)
add_executable(link_stack demo/include/link_stack.h demo/link_stack.c)
add_executable(test exp/stack.c)


