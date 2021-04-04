/*****************************************************************************
 *
 * Name: sq_stack.c
 * Date: 2021/3/27
 * Author: shaozk <https://github.com/shaozk>
 *
 * 顺序栈
 * 1.初始化    init_stack()
 * 2.判栈空    stack_empty()
 * 3.进栈      push()
 * 4.出栈      pop()
 * 5.读栈顶元素 get_top()
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10     // 定义栈中元素的最大个数

typedef struct {
    int data[MAXSIZE];  // 存放栈中元素
    int top;            // 栈顶指针
}*sq_stack;

/*
 * 初始化栈
 */
sq_stack init_stack() {
    sq_stack stack = (sq_stack)malloc(sizeof(sq_stack));
    if(!stack) {
        printf("\nmalloc failed\n");
        return NULL;
    }
    stack->top = -1;
    return stack;
}

/*
 * 栈判空
 */
bool stack_empty(sq_stack stack) {
    if(stack->top == -1) return true;

    else return false;
}

/*
 * 栈判满
 */
bool stack_full(sq_stack stack) {
    if(stack->top == MAXSIZE-1) return true;
    else return false;
}

/*
 * 进栈
 */
void push(sq_stack stack, int a) {
    // 栈满
    if(stack_full(stack)) {
        printf("stack is full\n");
        return;
    }
    stack->data[++stack->top] = a;
}

/*
 * 出栈
 */
void pop(sq_stack stack) {
    // 栈空
    if(stack_empty(stack)) {
        printf("stack is empty\n");
        return;
    }
    stack->data[stack->top--];
}

/*
 * 获取栈顶元素
 */
int get_top(sq_stack stack) {
    // 栈空
    if(stack_empty(stack)) {
        printf("stack is empty\n");
        exit(-1);
    }
    return stack->data[stack->top];
}


int main() {
    sq_stack stack = init_stack();
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    for(int i = 0; i < 10; i++) {
        push(stack, arr[i]);
    }
    for(int i = 0; i < 10; i++) {
        printf("%d ", get_top(stack));
        pop(stack);
    }
    return 0;
}




