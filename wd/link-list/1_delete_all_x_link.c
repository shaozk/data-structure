/*****************************************************************************
 *
 * Name: 1_delete_all_x_link.c
 * Date: 2021/3/19
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点
 *
 * 思路：
 *
 *****************************************************************************/

#include <stdlib.h>
#include <stdio.h>

// 单链表
typedef struct node {
    int data;
    struct node *next;
}node, *link_list;

/*
 * 头插法建立链表
 */
link_list init_list(link_list list, int a) {
    if(list == NULL) {
        // 表头结点为空，新建表头结点
        node *head = (node*)malloc(sizeof(node));
        if(head == NULL) {
            printf("malloc failed");
        }
        head->next = NULL;
        list = head;
    }
    node *temp = (node*)malloc(sizeof(node));
    temp->data = a;
    temp->next = list->next;
    list->next = temp;
    return list;
}

/*
 * 输出单链表
 */
void traverse_list(link_list list) {
    if(list == NULL) return;
    traverse_list(list->next);
    printf("%d ", list->data);
}


link_list delete_all_x_link(link_list list, int x) {
    if(list == NULL) return NULL;
    if(list->data == x) {
        node *temp = list;
        list = list->next;
        free(temp);
        return delete_all_x_link(list, x);
    } else {
        return delete_all_x_link(list->next, x);
    }

}

int main() {
    int arr[] = {1,2,3,4,5,5,7,8,9,0};
    link_list list = (node*)malloc(sizeof(node));
    list->next = NULL;
    for(int i = 0; i < 10; i++) {
        list = init_list(list, arr[i]);
    }
    traverse_list(list->next);
    printf("\n");
    delete_all_x_link(list->next, 5);
    traverse_list(list->next);
    return 0;
}