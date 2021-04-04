/*****************************************************************************
 *
 * Name: 13_merge_list_decrement.c
 * Date: 2021/3/22
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 13.假设有两个按元素值递增次序排列的线性表，均已单链表形式存储。请编写算法将这两
 * 个单链表归并为一个按元素值递减次序排列的单链表，并要求利用原来两个单链表的结点
 * 存放归并后的单链表。
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node, *link_list;

/*
 * 初始化
 */
link_list init_list() {
    link_list list = (node*)malloc(sizeof(node));
    if(!list) {
        puts("malloc failed");
        return NULL;
    }
    list->next = NULL;
    return list;
}

/*
 * 插入结点（头插）
 */
void insert_list(link_list list, int a) {
    if(!list) {
        puts("list not exit");
        return;
    }
    node *t = (node*)malloc(sizeof(node));
    t->data = a;
    t->next = list->next;
    list->next = t;
}

/*
 * 输出链表
 */
void traverse_list(link_list list){
    if(!list) return;
    traverse_list(list->next);
    printf("%d ", list->data);
}

/*
 * 合并链表
 */
link_list merge_list(link_list la, link_list lb) {
    node *pa = la->next, *pb = lb->next;
    node *p = la;
    while(pa || pb) {
        if(pa->data <= pb->data) {
            node *t = pa;
            pa = pa->next;
            t ->next = p->next;
            p->next = t;
        } else {
            node *t = pb;
            pb = pb->next;
            t ->next = p->next;
            p->next = t;
        }
        while(pa) {
            node *t = pa;
            pa = pa->next;
            t ->next = p->next;
            p->next = t;
        }
        while(pb) {
            node *t = pb;
            pb = pb->next;
            t ->next = p->next;
            p->next = t;
        }
    }
    return p;
}

int main() {
    link_list list = init_list();
    int arr[] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 10; i++) {
        insert_list(list, arr[i]);
    }
    node *p = merge_list(la, lb);
    traverse_list(list->next);

}
