cmake_minimum_required(VERSION 3.17)
project(data_structure C)

set(CMAKE_C_STANDARD 11)

include_directories(demo/include)
include_directories(wd/include)
include_directories(wd/include)

add_executable(sq_list demo/sq_list.c demo/include/sq_list.h)
add_executable(sq_stack demo/sq_stack.c demo/include/sq_stack.h)
add_executable(sq_queue demo/sq_queue.c demo/include/sq_queue.h)
add_executable(seq_list demo/seq_list.c demo/include/seq_list.h)
add_executable(link_list demo/link_list.c demo/include/link_list.h demo/utils/print.h)
add_executable(merge_list demo/merge_list.c demo/utils/print.h demo/include/link_list.h)
add_executable(reverse_list demo/reverse_list.c demo/utils/print.h)
add_executable(link_stack demo/include/link_stack.h demo/link_stack.c)

## tree
add_executable(binary_search_tree demo/tree/binary_search_tree.c demo/tree/binary_search_tree.h)

## string
add_executable(s_string demo/string/s_string.c demo/string/s_string.h)

# wangdao
## sq-list
add_executable(1_delete_min_element_sq wd/sq-list/1_delete_min_element_sq.c)
add_executable(2_reverse_sq wd/sq-list/2_reverse_sq.c)
add_executable(3_delete_x_element_sq wd/sq-list/3_delete_x_element_sq.c)
add_executable(4_5_delete_s2t_element_sq wd/sq-list/4_5_delete_s2t_element_sq.c)
add_executable(6_delete_duplicate_element wd/sq-list/6_delete_duplicate_element_sq.c)
add_executable(7_merge_order_list_sq wd/sq-list/7_merge_order_list_sq.c)
add_executable(8_reverse_sq_m_n_sq wd/sq-list/8_reverse_m_n_sq.c)
add_executable(9_find_element_insert_it_sq wd/sq-list/9_find_element_insert_it_sq.c)
add_executable(10_circular_shift_left_sq wd/sq-list/10_circular_shift_left_sq.c)
add_executable(11_find_the_median_sq wd/sq-list/11_find_the_median_sq.c)
add_executable(12_find_the_main_sq wd/sq-list/12_find_the_main_element_sq.c)

## link-list
add_executable(1_delete_all_x_link wd/link-list/1_delete_all_x_link.c)
add_executable(2_delete_all_x_with_head_link wd/link-list/2_delete_all_x_with_head_link.c)
add_executable(3_traverse_list_reverse wd/link-list/3_traverse_list_reverse.c)
add_executable(4_delete_list_min_element wd/link-list/4_delete_list_min_element.c)


# ustc
add_executable(1_greatest_common_divisor real-questions/ustc/1_greatest_common_divisor.c)
add_executable(2_train_ticket_booking real-questions/ustc/2_train_ticket_booking.c)
add_executable(3_shortest_path_minimum_cost real-questions/ustc/3_shortest_path_minimum_cost.c)

# cqu
add_executable(1_prime_number real-questions/cqu/1_prime_number.c)
add_executable(2_upper_to_lower real-questions/cqu/2_upper_to_lower.c)
add_executable(3_palindrome_number real-questions/cqu/3_palindrome_number.c)

# ahu
add_executable(1_odd_number_found real-questions/ahu/1_odd_number_found.c)
add_executable(2_find_the_perfect_number real-questions/ahu/2_find_the_perfect_number.c)
add_executable(3_word_length real-questions/ahu/3_word_length.c)

# bnu
add_executable(1_find_string_from_id real-questions/bnu/1_find_string_from_id.c)



