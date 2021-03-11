/*****************************************************************************
 *
 * Name: delete_x_element_sq.c
 * Date: 2021/3/9
 * Author: shaozk <https://github.com/shaozk>
 *
 * 问题：
 * 对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法
 * 删除线性表表中的所有值为x的数据元素
 *
 * 思路：
 * 1.遍历顺序表
 * 2.判断x元素是否等于顺序表中元素
 *      是：不管
 *      否：添加到顺序表中
 *
 *****************************************************************************/

#include <init_sq_list.h>

void delete_x_element_sq(sq_list *list, int elem) {
    if(list->length == 0) {
        printf("error!! list can't be null");
        exit(-1);
    }
    int k = 0;      // 记录不等于x的元素个数
    for(int i = 0; i < list->length; i++) {
        if(list->data[i] != elem) {
            list->data[k] = list->data[i];
            k++;
        }
    }
    list->length = k;

}

int main() {
    int arr[] = {1,2,3,4,5,3,7,8,9,3};
    sq_list *list = init_list_from_array_sq(arr, 10);
    print_list_sq(list);
    print_length_sq(list);

    delete_x_element_sq(list, 1);
    print_length_sq(list);
    print_list_sq(list);
}