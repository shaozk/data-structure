/*****************************************************************************
 *
 * Name: link_stack.h
 * Date: 2021/3/8
 * Author: shaozk <https://github.com/shaozk>
 *
 *****************************************************************************/


#ifndef DATA_STRUCTURE_LINK_STACK_H
#define DATA_STRUCTURE_LINK_STACK_H

#include<stdlib.h>
#include<stdio.h>

#define FALSE 0
#define TRUE 1


typedef struct stack_node {
    int data;
    struct stack_node *next;
}stack_node, *link_stack;

// 输出链栈
void print_list_link(link_stack S) {
    while(S->next) {
        printf("%d ", S->data);
        S = S->next;
    }
    printf("\n");
}


// 链栈初始化
link_stack init_stack_link() {
    stack_node *S = (stack_node*)malloc(sizeof(stack_node));
    if(!S) {
        printf("stack overflow\n");
    }
    S->next = NULL;
    return S;
}

// 入栈(头插法)
void push_stack(link_stack S, int e) {
    stack_node *node = (stack_node*)malloc(sizeof(stack_node));
    node->data = e;
    node->next = S;
    S = node;
}

#endif //DATA_STRUCTURE_LINK_STACK_H
