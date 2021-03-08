//
// Created by shaozk on 2021/3/8.
//


#ifndef DATA_STRUCTURE_SQSTACK_H
#define DATA_STRUCTURE_SQSTACK_H

/*
 * 顺序栈
 */
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10
#define SElemType int
#define Status int
#define FALSE 0
#define TRUE 1

typedef struct {
    SElemType data[MAXSIZE];
    int top;
}SqStack;

// 初始化顺序栈
SqStack* InitSqLStack() {
    SqStack *S;
    S = (SqStack*)malloc(sizeof(SqStack));
    if(!S) {
        printf("stack overflow\n");
        return NULL;
    }
    S->top = -1;
    return S;
}

// 判断栈满
Status IsSqFull(SqStack *S) {
    if(S->top == MAXSIZE - 1) {
        printf("stack overflow!!");
        return TRUE;
    }
    return FALSE;
}

// 判断栈空
Status IsSqEmpty(SqStack *S) {
    if(S->top == -1) {
        printf("stack is empty");
        return TRUE;
    }
    return FALSE;
}

// 入栈
Status SqPush(SqStack *S, SElemType e) {
    if(IsSqFull(S))
        return FALSE;
    S->data[++S->top] = e;
    return TRUE;
}

// 出栈
SElemType SqPop(SqStack *S) {
    if(IsSqEmpty(S)) {
        return FALSE;
    }
    return S->data[S->top--];
}

// 输出栈
void PrintSqStack(SqStack *S) {
    for(int i = 0; i <= S->top; i++) {
        printf("%d ", S->data[i]);
    }
    printf("\n");
}


#endif //DATA_STRUCTURE_SQSTACK_H


