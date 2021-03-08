/*****************************************************************************
 *
 * Name: sq_stack.h
 * Date: 2021/3/8
 * Author: shaozk <https://github.com/shaozk>
 *
 *****************************************************************************/


#ifndef DATA_STRUCTURE_SQ_STACK_H
#define DATA_STRUCTURE_SQ_STACK_H

/*
 * 顺序栈
 */
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10
#define Status int
#define FALSE 0
#define TRUE 1

typedef struct {
    int data[MAXSIZE];
    int top;
}sq_stack;

// 初始化顺序栈
sq_stack* init_stack_sq() {
    sq_stack *S;
    S = (sq_stack*)malloc(sizeof(sq_stack));
    if(!S) {
        printf("stack overflow\n");
        return NULL;
    }
    S->top = -1;
    return S;
}

// 判断栈满
Status is_full_sq(sq_stack *S) {
    if(S->top == MAXSIZE - 1) {
        printf("stack overflow!!");
        return TRUE;
    }
    return FALSE;
}

// 判断栈空
Status is_empty_sq(sq_stack *S) {
    if(S->top == -1) {
        printf("stack is empty");
        return TRUE;
    }
    return FALSE;
}

// 入栈
Status push_sq(sq_stack *S, int e) {
    if(is_full_sq(S))
        return FALSE;
    S->data[++S->top] = e;
    return TRUE;
}

// 出栈
int pop_sq(sq_stack *S) {
    if(is_empty_sq(S)) {
        return FALSE;
    }
    return S->data[S->top--];
}

// 输出栈
void print_stack_sq(sq_stack *S) {
    for(int i = 0; i <= S->top; i++) {
        printf("%d ", S->data[i]);
    }
    printf("\n");
}


#endif //DATA_STRUCTURE_SQ_STACK_H


