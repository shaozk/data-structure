/*****************************************************************************
 *
 * Name: 2_delete_all_x_with_head_link.c
 * Date: 2021/3/19
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一，
 * 试编写算法以实现上述操作。
 *
 * 思路：
 *
 *
 *****************************************************************************/

#include <init_link_list.h>

link_list delete_all_x_with_head_link(link_list list, int x) {
    link_list head = list->next;
    link_node *p = head;
    while(head) {
        if(head->data == x) {
            p = head;
            head = head->next;
            free(p);
        } else {
            head = head->next;
        }
    }
    return list;

}

int main() {
    // TODO:无头结点的链表


    return 0;
}
