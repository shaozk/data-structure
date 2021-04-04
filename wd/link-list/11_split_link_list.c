/*****************************************************************************
 *
 * Name: 11_split_link_list.c
 * Date: 2021/3/22
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 11.设C={a1,b1,a2,b2,...,an,bn}为线性表，采用带头结点的hc单链表存放，设计一个
 * 就地算法，将其拆分为两个线性表，使得A={a1,a2,...,an}，B={b1,b2,...,bn}。
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node, *link_list;

link_list init_list() {
    link_list list = (node *) malloc(sizeof(node));
    if (list == NULL) {
        printf("malloc failed");
        exit(-1);
    }
    list->next = NULL;
    return list;
}

link_list insert_list(link_list list, int a) {
    if(list == NULL) {
        printf("null pointer error");
        exit(-1);
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
    int a[] = {1,2,3,4,5,6,7,8,9,0};
    link_list list = NULL;
    list = init_list(list);
    for(int i = 0; i < 10; i++) {
        list = insert_list(list, a[i]);
    }
    node *la = list, *lb = list, *p = list->next;
    int ind = 0;
    while(p != NULL) {
        if (ind % 2 == 0) {
            p->next = la;
            la->next = p;
            p = p->next;
        } else {
            lb->next = p;
        }
    }

    traverse_list(list->next);

    return 0;
}
