/*****************************************************************************
 *
 * Name: 3_traverse_list_reverse.c
 * Date: 2021/3/21
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 3.设L为带头结点的单链表，编写算法实现从头到尾反向输出每个结点
 *
 * 思路：
 * 类似于树的后续遍历，但是头结点要另外处理。
 *
 *****************************************************************************/

#include <link_list.h>

void traverse_list_reverse(link_list list) {
    if(list == NULL) {
        return;
    }
    traverse_list_reverse(list->next);
    printf("%d ", list->data);
}

// 打印整型元素
void print_elem(int e) {
    printf("%d ", e);
}

int main() {
    link_list list = NULL;
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    list = init(list);
    for(int i = 1; i <= 10; i++) {
        list = list_insert(list, i, arr[i - 1]);
    }
    traverse_list_reverse(list->next);

}