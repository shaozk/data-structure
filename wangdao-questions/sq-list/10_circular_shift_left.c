/*****************************************************************************
 *
 * Name: 10_circular_shift_left.c
 * Date: 2021/3/13
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 10.【2010统考真题】设将n（n>1）个整数存放到一个一维数组R中。设计一个在时间和
 * 空间两方面都尽可能高效的算法。将R中保存的序列循环左移p（0<p<n）个位置，即将R中
 * 的数据由(X0,X1,...Xn-1)变换成(Xp,Xp+1,...,X0,X1,...,Xp-1)。要求：
 * 1）给出算法的基本设计思想.
 * 2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
 * 3）说明你所设计算法的时间复杂度和空间复杂度。
 *
 * 思路：
 * 可将这个问题视为数组ab转换成ba（a代表数组前p个元素，b带表余下n-p个元素），先将
 * a置逆，然后将b置逆，最后将整个数组置逆。
 *
 *****************************************************************************/

#include <init_sq_list.h>

sq_list* reverse_list(sq_list *list, int left, int right) {
    if(left > right || right > list->length) {
        printf("error! out of range");
        exit(-1);
    }
    int mid = (left + right) / 2;
    for(int i = left; i <= mid; i++) {
        int temp = list->data[i];
        list->data[i] = list->data[right - i + left];
        list->data[right - i + left] = temp;
    }
    return list;
}

sq_list* circular_shift_left(sq_list *list, int p) {
    if(p < 0 || p > list->length) {
        printf("error! out of range");
        exit(-1);
    }
    list = reverse_list(list, 0, p - 1);
    list = reverse_list(list, p, list->length - 1);
    list = reverse_list(list, 0, list->length - 1);
    return list;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    sq_list *list = init_list_from_array_sq(arr, 10);
    list = circular_shift_left(list, 5);
    print_list_sq(list);
    return 0;
}