//
// Created by shaozk on 2021/3/8.
//


#ifndef DATA_STRUCTURE_LINKSTACK_H
#define DATA_STRUCTURE_LINKSTACK_H

#include<stdlib.h>
#include<stdio.h>

#define ElemType int
#define Status int
#define FALSE 0
#define TRUE 1


typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
}StackNode, *LinkStack;

// 输出链栈
void PrintLinkStack(LinkStack S) {
    while(S->next) {
        printf("%d ", S->data);
        S = S->next;
    }
    printf("\n");
}


// 链栈初始化
LinkStack InitLinkStack() {
    StackNode *S = (StackNode*)malloc(sizeof(StackNode));
    if(!S) {
        printf("stack overflow\n");
    }
    S->next = NULL;
    return S;
}

// 入栈(头插法)
Status LinkPush(LinkStack S, ElemType e) {
    StackNode *node = (StackNode*)malloc(sizeof(StackNode));
    node->data = e;
    node->next = S;
    S = node;
//    PrintLinkStack(S);
    return TRUE;
}



#endif //DATA_STRUCTURE_LINKSTACK_H
