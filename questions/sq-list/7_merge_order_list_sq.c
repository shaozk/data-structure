/*****************************************************************************
 *
 * Name: merge_order_list_sq.c
 * Date: 2021/3/11
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 7.将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果的顺序表
 *
 * 思路：
 * 1.按顺序取出表头较小的表元素
 * 2.将剩下部分直接并入新的表
 *
 *****************************************************************************/


#include <init_sq_list.h>

sq_list* merge_order_list_sq(sq_list *la, sq_list *lb) {
    sq_list *l = init_list_sq();
    int i = 0, j = 0, k = 0;
    while(i < la->length && j < lb->length) {
        if(la->data[i] < lb->data[j]) {
            l->data[k++] = la->data[i++];
        } else {
            l->data[k++] = lb->data[j++];
        }
    }
    // la还有剩
    while(i < la->length) {
        l->data[k++] = la->data[i++];
    }
    // lb还有剩
    while(j < lb->length) {
        l->data[k++] = lb->data[j++];
    }
    l->length = k;
    return l;

}


int main() {
    int a[5] = {1,2,3,4,5};
    int b[5] = {1,3,5,7,9};
    sq_list *la = init_list_from_array_sq(a, 5);
    sq_list *lb = init_list_from_array_sq(b, 5);

    sq_list *lc = merge_order_list_sq(la, lb);
    print_list_sq(lc);
}