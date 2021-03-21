/*****************************************************************************
 *
 * Name: link_list.h
 * Date: 2021/3/8
 * Author: shaozk <https://github.com/shaozk>
 *
 * 线性表的链式实现--单链表
 *
 *****************************************************************************/

#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// 单链表的存储结构
typedef struct link_node {
    int data;                  // 结点的数据域
    struct link_node *next;    // 结点的指针域
} link_node, *link_list;       // link_list为指向结构体link_node的指针类型

/*
 * 构造一个空的线性表
 */
link_list init(link_list list) {
    if(list == NULL) {
        list = (link_node*)malloc(sizeof(link_node));
        list->next = NULL;
        if(list == NULL) {
            printf("malloc failed");
        }
    }
    return list;
}

/*
 * 销毁线性表
 */
link_list destroy_list(link_list list) {
    if(list == NULL) {
        return list;
    }
    link_node *temp = list->next;
    while(list->next) {
        temp = list->next;
        list->next = temp->next;
        free(temp);
    }
    return list;
}

/*
 * 将线性表置为空表
 */
link_list clear_list(link_list list) {

    return NULL;
}

/*
 * 判断线性表是否为空
 */
bool list_empty(link_list list) {
    // 链表只有头结点时，判定链表为空
    if(list != NULL && list->next == NULL) {
        return true;
    }
    return false;
}

/*
 * 获取线性表中元素个数
 */
unsigned int list_length(link_list list) {
    int len = 0;
    link_node *p = list->next;
    if(list == NULL || list->next == NULL) {
        return 0;   // 空表
    }
    while(p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

/*
 * 获取线性表中第i个元素（i从1开始，区别于数组下标）
 */
int get_elem(link_list list, int i) {

    return i;
}

/*
 * 返回线性表中第一个值与e相同的元素位置
 */
unsigned int locate_elem(link_list list, int e) {
    return 0;
}

/*
 * 若cur_e是线性表的数据元素，且不是第一个，返回其前驱
 */
int prior_elem(link_list list, int cur_e) {
    int pre_e;
    return pre_e;

}

/*
 * 若cur_e是线性表的数据元素，且不是第一个，返回其后继
 */
int next_elem(link_list list, int cur_e) {
    int next_e;
    return next_e;
}

/*
 * 在线性表第i个位置之前插入一个新的数据元素
 */
link_list list_insert(link_list list, int i, int e) {
    if(list == NULL) {
        printf("list not found");
        return NULL;
    }
    // 找到要插入的前一个位置
    link_node *temp = list;
    for(int j = 1; j < i; j++) {
        temp = temp->next;
        if(temp == NULL) {
            printf("out of range");
            return NULL;
        }
    }
    link_node *node = (link_node*)malloc(sizeof(link_node));
    node->data = e;
    // 插入结点
    node->next = temp->next;
    temp->next = node;
    return list;

    return list;
}

/*
 * 删除线性表的第i个元素
 */
link_list list_delete(link_list list, int i) {

    return list;
}

/*
 * 遍历线性表
 */
void traverse_list(link_list list, void(visit)(int)) {
    link_list p = list->next;
    // 确保链表存在且不为空表
    if(list == NULL || list->next == NULL) {
        return;
    }
    while(p != NULL) {
        visit(p->data);
        p = p->next;
    }

    printf("\n");
}


// 获取链表长度
unsigned int get_list_length_link(link_list list) {
    int len = 0;
    link_list p = list;
    while(p->next) {
        p = p->next;
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
    link_list p = list;
    while(p->next) {
        printf("%d ", p->next->data);
        p = p->next;
    }
    printf("\n");
}

// 初始化
link_list init_list_link() {
    link_list head = (link_node*)malloc(sizeof(link_node));    // 创建头指针
    head->next = NULL;
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






