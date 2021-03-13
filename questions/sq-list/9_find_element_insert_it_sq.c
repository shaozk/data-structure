/*****************************************************************************
 *
 * Name: 9_find_element_insert_it_sq.c
 * Date: 2021/3/13
 * Author: shaozk <https://github.com/shaozk>
 *
 * 问题：
 * 9.线性表(a1,a2,a3,...,an)中的元素递增有序且按顺序存储于计算机内。要求设计一个算法，
 * 完成用最少的时间在表中查找数值为x的元素，若找到，则将其与后继元素位置相互交换，若找
 * 不到，则将其插入表中并使表中元素仍递增有序。
 *
 * 思路：
 * 线性表递增排列，因此可以使用折半查询法。
 * 如果没有找到元素x，则根据折半查找的特性，可知在循环结束时，right<x<left,所以元素
 * x插在right后即可。
 *
 *****************************************************************************/
#include <init_sq_list.h>

sq_list* find_element_insert_it_sq(sq_list *list, int x) {
    int left = 0, right = list->length - 1, mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if(list->data[mid] == x) {
            // 找到，退出循环
            break;
        }
        if(list->data[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    // 若最后一个元素与x想等，则不必交换
    if(x == list->data[mid] && mid != list->length - 1){
        int temp = list->data[mid];
        list->data[mid] = list->data[mid + 1];
        list->data[mid + 1] = temp;
    }

    // 查找失败，插入元素
    if(left > right) {
        int i;
        for(i = list->length - 1; i > right; i--) {
            list->data[i + 1] = list->data[i];
        }
        list->data[i + 1] = x;
        list->length++;
    }
    return list;


}


int main() {
    int a1[] = {1,2,3,4,6,7,8,9,10,11};
    int a2[] = {1,2,3,4,5,6,7,8};
    sq_list *l1 = init_list_from_array_sq(a1, 10);
    sq_list *l2 = init_list_from_array_sq(a2, 8);
    l1 = find_element_insert_it_sq(l1, 5);
    print_list_sq(l1);

    l2 = find_element_insert_it_sq(l2, 4);
    print_list_sq(l2);

    return 0;
}