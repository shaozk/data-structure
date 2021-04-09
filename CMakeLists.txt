cmake_minimum_required(VERSION 3.17)
project(data_structure C)

set(CMAKE_C_STANDARD 11)

include_directories(demo/include)
include_directories(wd/include)
include_directories(wd/include)

add_executable(sq_list demo/sq_list.c demo/include/sq_list.h)
add_executable(seq_list demo/seq_list.c demo/include/seq_list.h)
add_executable(link_list demo/link_list.c demo/include/link_list.h demo/utils/print.h)
add_executable(merge_list demo/merge_list.c demo/utils/print.h demo/include/link_list.h)
add_executable(reverse_list demo/reverse_list.c demo/utils/print.h)

## tree
add_executable(binary_search_tree demo/tree/binary_search_tree.c demo/tree/binary_search_tree.h)
## string
add_executable(s_string demo/string/s_string.c demo/string/s_string.h)
## stack
add_executable(sq_stack demo/stack/sq_stack.c)
add_executable(link_stack demo/stack/link_stack.c)
## queue
add_executable(sq_queue demo/queue/sq_queue.c)
add_executable(link_queue demo/queue/link_queue.c)

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
add_executable(5_local_inversion wd/link-list/5_local_inversion_link.c)
add_executable(6_ascending_sort_link wd/link-list/6_ascending_sort_link.c)
add_executable(7_delete_between_n_m_list wd/link-list/7_delete_between_n_m_list.c)
add_executable(8_find_public_node wd/link-list/8_find_public_node.c)
add_executable(9_ascending_sort_print wd/link-list/9_ascending_sort_print.c)
add_executable(10_odd_even_separation wd/link-list/10_odd_even_separation.c)
add_executable(11_split_link_list wd/link-list/11_split_link_list.c)
add_executable(12_remove_duplicate_values wd/link-list/12_remove_duplicate_values.c)
add_executable(13_merge_list_decrement wd/link-list/13_merge_list_decrement.c)
add_executable(14_intersection_two_link wd/link-list/14_intersection_two_link.c)


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
add_executable(2_find_max_min real-questions/bnu/2_find_max_min.c)
add_executable(3_minimum_task_completion_time real-questions/bnu/3_minimum_task_completion_time.c)
#xmu
add_executable(1_wechat_sends_red_envelope real-questions/xmu/1_wechat_sends_red_envelope.c)
add_executable(2_quick_sort_pro real-questions/xmu/2_quick_sort_pro.c)
#nwu
add_executable(1_is_negative_number real-questions/nwu/1_is_negative_number.c)
add_executable(2_is_prime_number real-questions/nwu/2_is_prime_number.c)
add_executable(3_number_of_prime real-questions/nwu/3_number_of_prime.c)
add_executable(4_is_absolute_prime real-questions/nwu/4_is_absolute_prime.c)
add_executable(5_is_super_prime real-questions/nwu/5_is_super_prime.c)
add_executable(6_processing_strings real-questions/nwu/6_processing_strings.c)
add_executable(7_count_the_number_of_vowels real-questions/nwu/7_count_the_number_of_vowels.c)
add_executable(8_legal_identifier real-questions/nwu/8_legal_identifier.c)
add_executable(9_word_statistics real-questions/nwu/9_word_statistics.c)



