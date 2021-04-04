/*****************************************************************************
 *
 * Name: 10_odd_even_separation.c
 * Date: 2021/3/22
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 10.将一个带头结点的单链表A分解成两个带头结点的单链表A和B，使得A表中含有原表中序号
 * 为奇数的元素，而B表中含有原表中序号为偶数的元素，且保持相对顺序不变。
 *
 * 思路：
 * 为了保持原链表的顺序，使用尾插法建立新的链表
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node, *link_list;

link_list init_list(link_list list, int a) {
    if(list == NULL) {
        list = (node*)malloc(sizeof(node));
        if(list == NULL) {
            printf("malloc failed");
            return NULL;
        }
        list->next = NULL;
    }
    node *temp = (node*)malloc(sizeof(node));
    temp->data = a;
    temp->next = list->next;
    list->next = temp;
    return list;
}

void traverse_list(link_list list) {
    if(list == NULL) return;
    traverse_list(list->next);
    printf("%d ", list->data);
}

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9};
    link_list list = NULL;
    link_list lb = (node*)malloc(sizeof(node));
    lb->next = NULL;
    for(int i = 0; i < 9; i++) {
        list = init_list(list, a[i]);
    }
    node *odd = list->next, *pre = list;
    node *even = lb;
    while(odd != NULL) {
        // 如果是偶数
        if(odd->data % 2 == 0) {
            // 删除该结点
            node *temp = odd;
            odd = odd->next;
            pre->next = odd;

            // 将该结点插入lb中（尾插）
            temp->next = NULL;
            even->next = temp;
            even = even->next;
        } else {
            pre = odd;
            odd = odd->next;
        }
    }

    traverse_list(list->next);
    putchar('\n');
    traverse_list(lb->next);


    return 0;
}
