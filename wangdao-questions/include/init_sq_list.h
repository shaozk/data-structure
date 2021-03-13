/*****************************************************************************
 *
 * Name: init_sq_list.c
 * Date: 2021/3/9
 * Author: shaozk <https://github.com/shaozk>
 *
 * 通过数组初始化顺序表，方便使用
 *
 *****************************************************************************/
#include <sq_list.h>

sq_list* init_list_from_array_sq(int *arr, int n) {
    sq_list *list = init_list_sq();
    for(int i = 0; i < n; i++) {
        append_list_sq(list, arr[i]);
    }
    return list;
}

