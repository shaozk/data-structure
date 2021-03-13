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
add_executable(1_delete_min_element_sq questions/sq-list/1_delete_min_element_sq.c)
add_executable(2_reverse_sq questions/sq-list/2_reverse_sq.c)
add_executable(3_delete_x_element_sq questions/sq-list/3_delete_x_element_sq.c)
add_executable(4_5_delete_s2t_element_sq questions/sq-list/4_5_delete_s2t_element_sq.c)
add_executable(6_delete_duplicate_element questions/sq-list/6_delete_duplicate_element_sq.c)
add_executable(7_merge_order_list_sq questions/sq-list/7_merge_order_list_sq.c)
add_executable(8_reverse_sq_m_n_sq questions/sq-list/8_reverse_m_n_sq.c)
add_executable(9_find_element_insert_it_sq questions/sq-list/9_find_element_insert_it_sq.c)




