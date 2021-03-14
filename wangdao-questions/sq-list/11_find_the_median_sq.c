/*****************************************************************************
 *
 * Name: 11_find_the_median_sq.c
 * Date: 2021/3/13
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 11.【2011统考真题】一个长度为L（L>=1）的升序序列S，处在第[L/2]个位置的数称为S
 * 的中位数。例如，若序列S1=（11，13，15，17，19）,则S1的中位数是15，两个序列的
 * 中位数是他们所有元素的升序序列的中位数。例如，若S2=（2，4，6，8，20），则S1和S2
 * 的中位数是11。现在有两个等长序升序序列A和B，试设计一个在时间和空间两方面都尽可能
 * 高效的算法，找出两个序列A和B的中位数。要求：
 * 1）给出算法的基本设计思想。
 * 2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
 * 3）说明你所设计算法的时间复杂度和空间复杂度。
 *
 * 思路：
 * 根据中位数的性质，中位数左边的数全部比它小，在顺序表S1和S2中，找到第L-1小的数，
 * 然后第L个数即是中位数。
 *
 *****************************************************************************/

#include <init_sq_list.h>

int find_the_median_sq(sq_list *l1, sq_list *l2) {
    int mid_ind = (l1->length + l2->length) / 2;
    int i = 0, j = 0, mid = 0;
    while(mid_ind > 0) {
        if(l1->data[i] < l2->data[j]) {
            mid = l1->data[i++];
        } else {
            mid = l2->data[j++];
        }
        mid_ind--;
    }
    return mid;
}

int main() {
    int a1[] = {11,13,15,17,19};
    int a2[] = {2,4,6,8,20};
    sq_list *l1 = init_list_from_array_sq(a1, 5);
    sq_list *l2 = init_list_from_array_sq(a2, 5);
    int median = find_the_median_sq(l1, l2);
    printf("%d\n",median);
    return 0;
}


