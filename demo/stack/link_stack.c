/*****************************************************************************
 *
 * Name: link_stack.c
 * Date: 2021/3/27
 * Author: shaozk <https://github.com/shaozk>
 *
 * 链栈
 * 1.初始化
 * 2.判栈满(无，无需判满)
 * 3.判栈空
 * 4.压栈
 * 5.出栈
 * 6.获取栈顶元素
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
}node, *link_stack;

link_stack init_stack() {
    link_stack stack = (node*)malloc(sizeof(node));
    if(!stack) {
        printf("malloc failed\n");
        return NULL;
    }
    stack->next = NULL;
    return stack;
}

/*
 * 判空
 */
bool stack_empty(link_stack stack) {
    if(stack->next == NULL) return true;
    else return false;
}

/*
 * 压栈
 */
void push(link_stack stack, int a) {
    node *t = (node*)malloc(sizeof(node));
    t->data = a;
    t->next = stack->next;
    stack->next = t;
}

/*
 * 出栈
 */
void pop(link_stack stack) {
    if(stack_empty(stack)) {
        printf("stack is empty");
        return;
    }
    node *t = stack->next;
    stack->next = t->next;
    free(t);
}

/*
 * 获取栈顶元素
 */
int get_top(link_stack stack) {
    if(stack_empty(stack)) {
        printf("stack is empty");
        return -1;
    }
    return stack->next->data;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    link_stack stack = init_stack();
    for(int i = 0; i < 10; i++ ){
        push(stack, arr[i]);
    }
    for(int i = 0; i < 10; i++) {
        printf("%d ", get_top(stack));
        pop(stack);
    }


    return 0;
}


