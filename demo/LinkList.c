//
// Created by shaozk on 2021/3/6.
//

#include<stdio.h>
#include<stdlib.h>

#include "LinkList.h"
#include "../utils/print.h"

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
    PrintLinkLength(L);
    printf("list:\t");
    while(L->next) {
        printf("%d ", L->next->data);
        L = L->next;
    }
    printf("\n");
}

// 初始化(包含头指针的单链表)
LinkList InitLinkList() {
    LinkList head = (LNode*)malloc(sizeof(LNode));    // 创建头指针
    head->next = NULL;
    LinkList temp = head;
    for(int i = 1; i < 6; i++) {
        LNode *node=(LNode*)malloc(sizeof(LNode));
        node->data=i;
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
            Print("error");
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




int main(){
    // 初始化链表
    Print("\n--init link list--\n");
    LinkList L = InitLinkList();
    PrintLinkList(L);

    // 插入元素
    Print("\n--insert link list--\n");
    InsertLinkList(L, 2, 99);
    PrintLinkList(L);

    // 删除元素
    Print("\n--delete link list--\n");
    DeleteLinkList(L, 2);
    PrintLinkList(L);

    // 查找结点的值
    Print("\n--locate link list--\n");
    ElemType e = LocateLinkList(L, 5);
    printf("elem:\t%d\n", e);



    return 0;
}
