cmake_minimum_required(VERSION 3.17)
project(data_structure C)

set(CMAKE_C_STANDARD 11)

include_directories(demo/include)
include_directories(questions/include)

add_executable(sq_list demo/sq_list.c demo/include/sq_list.h)
add_executable(sq_stack demo/sq_stack.c demo/include/sq_stack.h)
add_executable(sq_queue demo/sq_queue.c demo/include/sq_queue.h)
add_executable(seq_list demo/seq_list.c demo/include/seq_list.h)
add_executable(link_list demo/link_list.c demo/include/link_list.h demo/utils/print.h)
add_executable(merge_list demo/merge_list.c demo/utils/print.h demo/include/link_list.h)
add_executable(reverse_list demo/reverse_list.c demo/utils/print.h)
add_executable(link_stack demo/include/link_stack.h demo/link_stack.c)
add_executable(test exp/stack.c)

# sq-list
add_executable(delete_min_element_sq questions/sq-list/delete_min_element_sq.c)
add_executable(reverse_sq questions/sq-list/reverse_sq.c)
add_executable(delete_x_element_sq questions/sq-list/delete_x_element_sq.c)
add_executable(delete_s2t_element_sq questions/sq-list/delete_s2t_element_sq.c)



