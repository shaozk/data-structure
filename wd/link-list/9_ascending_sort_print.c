/*****************************************************************************
 *
 * Name: 9_ascending_sort_print.c
 * Date: 2021/3/22
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 9.给定一个带头结点的单链表，设head为头指针，结点结构为（data,next），data为整型
 * 元素，next为指针，试写出算法，按递增次序输出单链表中各个结点的数据元素，并释放结点
 * 所占的存储空间（要求：不允许使用数组作为辅助空间）
 *
 * 思路：
 * 遍历链表，每次找到最小结点，并删除
 *
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
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
    if(list == NULL) {
        printf("list no node");
        return;
    }
    traverse_list(list->next);
    printf("%d ", list->data);
}

int find_list_min(link_list list) {
    if(list == NULL) return 0;
    node *p = list->next;
    int min = p->data;
    while(p != NULL){
        if(p->data < min) {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

link_list delete_list_min(link_list list, int min) {
    if(list == NULL) return NULL;
    node *p = list->next, *pre = list;
    while(p != NULL) {
        if(p->data == min) {
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

void ascending_sort(link_list list) {
    node *p = list;
    while(p->next != NULL) {
        int min = find_list_min(p);
        printf("%d ", min);
        p = delete_list_min(p, min);
    }
}


int main() {
    int a[] = {3,2,1,4,5,6};
    link_list list = NULL;
    for(int i = 0; i < 6; i++) {
        list = init_list(list, a[i]);
    }
    ascending_sort(list);
    putchar('\n');
    traverse_list(list->next);

    return 0;
}

