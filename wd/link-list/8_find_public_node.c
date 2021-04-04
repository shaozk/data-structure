/*****************************************************************************
 *
 * Name: 8_find_public_node.c
 * Date: 2021/3/22
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 给定两个的单链表，编写算法找出两个链表的公共结点
 * TODO:构建有公共结点的链表
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
    // 头插法
    node *temp = (node*)malloc(sizeof(node));
    temp->data = a;
    temp->next = list->next;
    list->next = temp;
    return list;
}


void traverse_list(link_list list) {
    if (list == NULL) return;
    traverse_list(list->next);
    printf("%d ", list->data);
}

link_list append_list(link_list l1, link_list l2) {
    if(l1 == NULL) return l2;
    node *p = l1->next;
    while(p != NULL) {
        p = p->next;
    }
    p->next = l2->next;
    return l1;
}



int main() {
    int a[] = {1,2,3,4,5,6}, b[] = {2,5,3,4,6}, c[] = {8,7,6,5,8,7};
    link_list l1 = NULL, l2 = NULL, l3 = NULL;
    for(int i = 0; i < 6; i++) {
        l1 = init_list(l1, a[i]);
        l3 = init_list(l3, c[i]);
    }
    for(int i = 0; i < 5; i++) {
        l2 = init_list(l2, b[i]);
    }

    traverse_list(l1->next);
    putchar('\n');
    traverse_list(l2->next);
    putchar('\n');
    traverse_list(l3->next);
    putchar('\n');
    l1 = append_list(l1, l3);
    traverse_list(l1);

    return 0;
}