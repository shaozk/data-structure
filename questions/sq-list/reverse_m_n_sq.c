/*****************************************************************************
 *
 * Name: reverse_m_n_sq.c
 * Date: 2021/3/13
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 已知在以为数组A[m+n]中依次存放两个线性表(a1,a2,a3,...,am)和(b1,b2,b3,...,bn)。
 * 试编写程序，将数组中两个顺序表的位置互换，即将(b1,b2,b3,...,bn)放在(a1,a2,a3,..
 * .,am)前面。
 *
 * 思路：
 * 1.将整个顺序表逆转
 * 2.分别将a，b逆转
 *
 *****************************************************************************/

#include <init_sq_list.h>

// 顺序表逆转
sq_list* reverse_sq(sq_list *list, int left, int right) {
    if (left > right || right > list->length) {
        printf("error! out of range");
        exit(-1);
    }
    int mid = (left + right + 1) / 2;
    int temp;
    for(int i = left; i < mid; i++) {
        temp = list->data[i];
        list->data[i] = list->data[right - i + left];
        list->data[right - i + left] = temp;
    }
    return list;

}

sq_list* reverse_m_n_sq(sq_list *list, int m, int n) {
    list = reverse_sq(list, 0, m + n - 1);
    list = reverse_sq(list, 0, m - 1);
    list = reverse_sq(list, m, m + n - 1);
    return list;
}


int main(){
    int a1[] = {1,2,3,4,5,6,7,8,9};
    int a2[] = {6,5,4,3,2,1};
    int a3[] = {1,2,3,4,5,6,5,4,3,2,1};
    sq_list *l1 = init_list_from_array_sq(a1, 9);
    sq_list *l2 = init_list_from_array_sq(a2, 6);
    sq_list *l3 = init_list_from_array_sq(a3, 11);
    l1 = reverse_sq(l1, 2, 6);
    l2 = reverse_sq(l2, 1, 5);
    print_list_sq(l1);
    print_list_sq(l2);

    l3 = reverse_m_n_sq(l3, 5, 6);
    print_list_sq(l3);


    return 0;
}