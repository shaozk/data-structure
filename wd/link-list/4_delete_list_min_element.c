/*****************************************************************************
 *
 * Name: 4_delete_list_min_element.c
 * Date: 2021/3/21
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 4.试编写在带头结点的单链表L中删除一个最小值结点的高效算法（假设最小值是唯一的）
 *
 * 思路：
 * 
 *
 *
 *****************************************************************************/

#include <link_list.h>

link_list* delete_list_min_element(link_list list) {
    if(list == NULL) {
        return NULL;
    }
    // 找到最小元素位置i及元素值value
    int i = 1;

    delete_list(list, i);
    return list;
}

int main() {

    return 0;
}