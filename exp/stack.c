//
// Created by shaozk on 2021/3/8.
//

#include<stdlib.h>
#include<stdio.h>

typedef struct stack{
    int data;
    struct stack *next;
}stack;

stack* init_stack(stack *s) {
    s = NULL;
    return s;
}

// 入栈
stack* push(stack *s, int e) {
    stack *node = (stack*)malloc(sizeof(stack));
    node->data = e;
    node->next = s;
    s = node;
    return s;
}

// 出栈
stack* pop(stack *s) {
    if(s == NULL)
        return NULL;
    stack *node = (stack*)malloc(sizeof(stack));
    node = s;
    s = s->next;
    free(node);
    return s;
}

// 获取栈顶元素
int get_top(stack *s) {
    if(s != NULL)
        return s->data;
    else return -1;
}

// 获取链表长度
int size(stack *s) {
    int num = 0;
    stack *node = s;
    while(node) {
        num++;
        node = node->next;
    }
    return num;

}

int main() {
    stack *s = NULL;
    s = init_stack(s);
    for(int i = 0; i < 10; i++) {
        s = push(s, i + 1);
    }
    printf("%d\n", get_top(s));

    s = pop(s);
    printf("%d\n", get_top(s));

    printf("%d\n", size(s));

    return 0;

}



