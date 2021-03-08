//
// Created by shaozk on 2021/3/6.
//
#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include<stdlib.h>
#include "../utils/print.h"

/*单链表*/

#define ElemType int

// 单链表的存储结构
typedef struct LNode {
    ElemType data;          // 结点的数据域
    struct LNode *next;     // 结点的指针域
} LNode, *LinkList;      // LinkList为指向结构体LNode的指针类型

// 获取链表长度
int GetLinkLength(LinkList L) {
    int len = 0;
    while(L->next) {
        L = L->next;
        len++;
    }
    return len;
}

// 输出链表长度
void PrintLinkLength(LinkList L) {
    printf("length:\t%d\n", GetLinkLength(L));
}

// 链表显示
void PrintLinkList(LinkList L) {
    printf("list:\t");
    while(L->next) {
        printf("%d ", L->next->data);
        L = L->next;
    }
    printf("\n");
}

// 初始化(包含头指针的单链表)
LinkList InitLinkList(ElemType *arr, int n) {
    LinkList head = (LNode*)malloc(sizeof(LNode));    // 创建头指针
    head->next = NULL;
    LinkList temp = head;
    for(int i = 0; i <= n; i++) {
        LNode *node=(LNode*)malloc(sizeof(LNode));
        node->data=arr[i];
        node->next=NULL;
        temp->next=node;
        temp=temp->next;
    }
    return head;
}

// 插入
LinkList InsertLinkList(LinkList L, int i, ElemType e) {
    LNode *temp = L;    // 创建临时结点
    // 找到插入位置的上一个结点
    for(int j = 1; j < i; j++) {
        temp = temp->next;
        if(temp == NULL) {
            Print("error");
            return L;
        }
    }
    // 创建插入结点
    LNode *node = (LNode*)malloc(sizeof(LNode));
    node->data = e;
    // 插入结点
    node->next = temp->next;
    temp->next = node;
    return L;
}


// 删除
LinkList DeleteLinkList(LinkList L, int i) {
    // 创建临时结点
    LNode *temp = L;
    // 找到删除元素的上一个结点
    for(int j = 1; j < i; j++) {
        temp = temp->next;
        if(temp == NULL) {
            return L;
        }
    }
    // 保存要删除的结点
    LNode *del = temp->next;
    // 删除结点
    temp->next = temp->next->next;
    // 释放所删除结点，避免内存泄漏
    free(del);
    return L;

}

// 查找结点的值
ElemType LocateLinkList(LinkList L, int i) {
    // 创建临时结点
    LNode *temp = L;
    while(i) {
        temp = temp->next;
        i--;
    }
    return temp->data;
}



#endif // _LINKLIST_H_






