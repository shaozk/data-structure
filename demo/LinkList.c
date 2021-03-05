/*单链表*/
#include<stddef.h>     // 包含NULL的定义
#include<stdio.h>
#include<stdlib.h>  

#define ElemType int
#define ERROR -2

// 单链表的存储结构
typedef struct LNode {
    ElemType data;      // 结点的数据域 
    struct LNode *next;        // 结点的指针域
}LNode, *LinkList;      // LinkList为指向结构体LNode的指针类型

// 初始化
LinkList InitList() {
    // 构造一个空的单链表
    LinkList head = (LNode*)malloc(sizeof(LNode));    // 创建头指针
    head->next = NULL;
    LNode *temp = head;
    for(int i = 1; i < 6; i++) {
        LNode *node=(LNode*)malloc(sizeof(LNode));
        node->data=i;
        node->next=NULL;
        temp->next=node;
        temp=temp->next;
    }
    return head;
}

// 取值
ElemType GetElem(LinkList list, int ind) {
    LNode *p = list->next;
    int i = 1;
    while(p && i < ind) {
        p = p->next;
        i++;
    }
    if(!p || i > ind) return ERROR;
    return p->data;
}

// 查找
LNode* LocateElem(LinkList list, ElemType e) {
    LNode *p = list->next;
    while(p && p->data != e) {
        p = p->next;
    }
    return p;
}

// 插入


// 删除

// 创建单链表

// 链表显示
void display(LinkList list) {
    while(list) {
        printf("-> %d ", list->next->data);
        list = list->next;
    }
    printf("\n");
}


void main(){
    LinkList list = InitList();
    ElemType a = GetElem(list, 2);
    printf("%d\n", a);
    LinkList l = LocateElem(list, 3);
    display(l);
    display(list);
}
