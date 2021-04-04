/*****************************************************************************
 *
 * Name: 12_remove_duplicate_values.c
 * Date: 2021/3/22
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 12.在一个递增有序的线性表中，有数值相同的元素存在若存储方式为单链表，设计算法
 * 去掉数值相同的元素，使表中不再有重复的元素，例如（7,10,21,30,42,42,42,51,70）
 * 将变为(7,10,21,30,42,51,70)
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
    // 新建头结点
    node *list = (node*)malloc(sizeof(node));
    if(!list) {
        printf("malloc failed\n");
        return NULL;
    }
    list->next = NULL;
    return list;
}

/*
 * 头插法
 */
link_list insert_list(link_list list, int a) {
    if(!list) {
        printf("list is empty\n");
        return NULL;
    }
    // 新建结点
    node *t = (node*)malloc(sizeof(node));
    t->data = a;
    t->next = list->next;
    list->next = t;
    return list;
}

/*
 * 输出链表
 */
void traverse_list(link_list list) {
    if(!list) return;
    traverse_list(list->next);
    printf("%d ", list->data);
}

/*
 * 删除重复结点
 */
link_list delete_duplicate_elem(link_list list) {
    node* p = list->next, *pre = list;
    // 如果当前结点元素等于下一个结点的元素，删除
    while(p->next) {
        if(p->data == p->next->data) {
            node *t = p;
            p = p->next;
            pre->next = p;
            free(t);
        } else {
            pre = p;
            p = p->next;
        }
    }
    return list;

}

int main() {
    int arr[] = {10,21,30,42,42,42,70,70,70};
    link_list list = init_list();
    for(int i = 0; i < 9; i++) {
        list = insert_list(list, arr[i]);
    }
    list = delete_duplicate_elem(list);
    traverse_list(list->next);
    return 0;
}
