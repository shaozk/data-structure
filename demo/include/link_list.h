/*****************************************************************************
 *
 * Name: link_list.h
 * Date: 2021/3/8
 * Author: shaozk <https://github.com/shaozk>
 *
 *****************************************************************************/

#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
/*
 * 单链表
 */

#include<stdlib.h>

// 单链表的存储结构
typedef struct link_node {
    int data;          // 结点的数据域
    struct link_node *next;    // 结点的指针域
} link_node, *link_list;      // link_list为指向结构体link_node的指针类型

// 获取链表长度
int get_list_length_link(link_list list) {
    int len = 0;
    while(list->next) {
        list = list->next;
        len++;
    }
    return len;
}

// 输出链表长度
void print_list_length(link_list list) {
    printf("length:\t%d\n", get_list_length_link(list));
}

// 链表显示
void print_list_link(link_list list) {
    printf("list:\t");
    while(list->next) {
        printf("%d ", list->next->data);
        list = list->next;
    }
    printf("\n");
}

// 初始化(包含头指针的单链表)
link_list init_list_link(const int *arr, int n) {
    link_list head = (link_node*)malloc(sizeof(link_node));    // 创建头指针
    head->next = NULL;
    link_list temp = head;
    for(int i = 0; i <= n; i++) {
        link_node *node=(link_node*)malloc(sizeof(link_node));
        node->data=arr[i];
        node->next=NULL;
        temp->next=node;
        temp=temp->next;
    }
    return head;
}

// 插入
link_list insert_list_link(link_list L, int i, int e) {
    link_node *temp = L;    // 创建临时结点
    // 找到插入位置的上一个结点
    for(int j = 1; j < i; j++) {
        temp = temp->next;
        if(temp == NULL) {
            printf("error");
            return L;
        }
    }
    // 创建插入结点
    link_node *node = (link_node*)malloc(sizeof(link_node));
    node->data = e;
    // 插入结点
    node->next = temp->next;
    temp->next = node;
    return L;
}

// 删除
link_list delete_list_link(link_list L, int i) {
    // 创建临时结点
    link_node *temp = L;
    // 找到删除元素的上一个结点
    for(int j = 1; j < i; j++) {
        temp = temp->next;
        if(temp == NULL) {
            return L;
        }
    }
    // 保存要删除的结点
    link_node *del = temp->next;
    // 删除结点
    temp->next = temp->next->next;
    // 释放所删除结点，避免内存泄漏
    free(del);
    return L;

}

// 查找结点的值
int locate_list_link(link_list L, int i) {
    // 创建临时结点
    link_node *temp = L;
    while(i) {
        temp = temp->next;
        i--;
    }
    return temp->data;
}

#endif // _LINK_LIST_H_






