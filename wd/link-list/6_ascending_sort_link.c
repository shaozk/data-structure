/*****************************************************************************
 *
 * Name: 6_ascending_sort_link.c
 * Date: 2021/3/22
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 有一个带头结点的单链表L，设计一个算法使其元素递增有序。
 *
 * 思路:
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node, *link_list;

/*
 * 头插法
 */
link_list init_list(link_list list, int a) {
    if(list == NULL) {
        list = (node*)malloc(sizeof(node));
        if(list == NULL) {
            printf("malloc failed");
            return NULL;
        }
        list->next = NULL;
    }
    // 新建一个结点
    node *temp = (node*)malloc(sizeof(node));
    temp->data = a;
    temp->next = list->next;
    list->next = temp;
    return list;
}

/*
 * 输出链表
 */
void traverse_list(link_list list) {
    if(list == NULL) return;
    traverse_list(list->next);
    printf("%d ", list->data);
}

link_list ascending_sort(link_list list) {
    node *p = list->next, *pre, *r = p->next;
    p->next = NULL; // 处理首结点
    p = r;
    while(p) {
        r = p->next;    // 保存p的后继结点
        pre = list;
        while(pre->next != NULL && pre->next->data > p->data) {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
    return list;
}


int main() {
    int arr[5] = {2,1,5,3,4};
    link_list list = NULL;
    for(int i = 0; i < 5; i++) {
        list = init_list(list, arr[i]);
    }
    traverse_list(list->next);
    puts("");
    list = ascending_sort(list);
    traverse_list(list->next);

    return 0;
}



