/*****************************************************************************
 *
 * Name: init_link_list.h
 * Date: 2021/3/19
 * Author: shaozk <https://github.com/shaozk>
 *
 *****************************************************************************/
#ifndef DATA_STRUCTURE_INIT_LINK_LIST_H
#define DATA_STRUCTURE_INIT_LINK_LIST_H

#include <link_list.h>

// 从数组初始化链表（含有头结点）
link_list init_list_from_array_with_head(const int *arr, int n) {
    link_list head = (link_node*)malloc(sizeof(link_node));    // 创建头指针
    head->next = NULL;
    link_list temp = head;
    for(int i = 0; i < n; i++) {
        link_node *node=(link_node*)malloc(sizeof(link_node));
        node->data=arr[i];
        node->next=NULL;
        temp->next=node;
        temp=temp->next;
    }
    return head;
}

link_list init_list_from_array_without_head(const int *arr, int n) {
    link_list p = (link_node*)malloc(sizeof(link_node));    // 创建头指针
    link_list temp = p;
    for(int i = 0; i < n; i++) {
        link_node *node=(link_node*)malloc(sizeof(link_node));
        node->data=arr[i];
        node->next=NULL;
        temp=node;
        temp=temp->next;
    }
    return p;
}

#endif //DATA_STRUCTURE_INIT_LINK_LIST_H
