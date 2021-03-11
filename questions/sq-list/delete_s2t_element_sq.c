/*****************************************************************************
 *
 * Name: delete_s2t_element_sq.c
 * Date: 2021/3/11
 * Author: shaozk <https://github.com/shaozk>
 *
 * 问题：
 * 从有序顺序表中删除其值在给定s与t之间（要求s<t）的所有元素，若s或t不合法
 * 或者顺序表为空，则显示出错误信息并退出运行。
 *
 * 思路：
 * 1.遍历顺序表
 * 2.错误处理
 * 3.判断元素是否在s~t之间
 *    是：不管
 *    否：添加到顺序表中
 *
 *****************************************************************************/

#include <init_sq_list.h>

void delete_s2t_element_sq(sq_list *list, int s, int t) {
    if(list->length <= 0) {
        printf("error! sq list can't be null");
        exit(-1);
    }
    if(s >= t) {
        printf("s must be smaller than t");
        exit(-1);
    }
    int ind = 0;
    for (int i = 0; i < list->length; ++i) {
        if (list->data[i] < s || list->data[i] > t) {
            list->data[ind] = list->data[i];
            ind++;
        }
    }
    list->length = ind;

}


int main() {
    int arr[10] = {1,2,2,5,2,5,6,6,2,8};
    sq_list *list = init_list_from_array_sq(arr, 10);
    print_list_sq(list);
    delete_s2t_element_sq(list, 1, 3);
    print_list_sq(list);
    return 0;
}