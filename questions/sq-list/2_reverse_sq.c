/*****************************************************************************
 *
 * Name: reverse_sq.c
 * Date: 2021/3/9
 * Author: shaozk <https://github.com/shaozk>
 *
 * 问题：
 * 2.设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)
 *
 * 思路：
 * 1.遍历顺序表前半部分
 * 2.前半部分元素L.data[L.length/2]与后半部分元素L.data[L.length-i-1]交换
 *
 *****************************************************************************/

#include <init_sq_list.h>

// 顺序表逆转
void reverse_sq(sq_list *list) {
    int temp, len = list->length;
    for(int i = 0; i < len / 2; i++) {
        temp = list->data[i];
        list->data[i] = list->data[len - i -1];
        list->data[len - i - 1] = temp;
    }
}

int main() {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    sq_list *list = init_list_from_array_sq(arr, 10);
    print_list_sq(list);

    reverse_sq(list);
    print_list_sq(list);

}
