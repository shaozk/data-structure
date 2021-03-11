/*****************************************************************************
 *
 * Name: delete_duplicate_element_sq.c
 * Date: 2021/3/11
 * Author: shaozk <https://github.com/shaozk>
 *
 * 问题：
 * 从有序表中删除所有重复的元素，使得表中所有元素的值均不同
 *
 * 思路：
 * 注意是有序表，所有重复的元素都是前后相邻，判断前后是否相等，相同，
 * 继续向后判断，不同，则插入前面的元素至有序表
 *
 *****************************************************************************/
#include <init_sq_list.h>

void delete_duplicate_element_sq(sq_list *list) {
    if(list->length <= 0) {
        printf("error!! list can't be null");
        exit(-1);
    }
    int ind = 0;
    for(int i = 1; i < list->length; i++) {
        if(list->data[i] != list->data[i-1]) {
            list->data[ind] = list->data[i-1];
            ind++;
        }
    }
    list->length = ind;

}

int main(){
    int arr[] = {1,2,2,2,2,2,3,3,3,4,4,5};
    sq_list *list = init_list_from_array_sq(arr, 12);
    print_list_sq(list);
    delete_duplicate_element_sq(list);
    print_list_sq(list);

    return 0;

}