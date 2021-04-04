/*****************************************************************************
 *
 * Name: sq_queue.c
 * Date: 2021/3/27
 * Author: shaozk <https://github.com/shaozk>
 *
 * 顺序队列
 * 1.初始化    init_queue()
 * 2.判队空    queue_empty()
 * 3.判队满    queue_full()
 * 4.入队      en_queue()
 * 5.出队      de_queue()
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10

typedef struct {
    int data[MAXSIZE];  // 存放队列元素
    int front,rear;     // 队头指针和队尾指针
}node,*sq_queue;

/*
 * 初始化队列
 */
sq_queue init_queue() {
    sq_queue queue = (node*)malloc(sizeof(node));
    if(!queue) {
        printf("malloc failed");
        return NULL;
    }
    queue->front = queue->rear = 0;
    return queue;
}

/*
 * 队列判空
 */
bool queue_empty(sq_queue queue) {
    if(queue->front == queue->rear) return true;
    else return false;
}

/*
 * 队列判满
 */
bool queue_full(sq_queue queue) {
    if(queue->rear+1 % MAXSIZE == queue->front) return true;
    else return false;
}

/*
 * 入队列
 */
void en_queue(sq_queue queue, int a) {
    if(queue_full(queue)) {
        printf("queue is full\n");
        return;
    }
    queue->data[queue->rear] = a;
    queue->rear = (queue->rear + 1) % MAXSIZE;
}

/*
 * 出队列
 */
void de_queue(sq_queue queue) {
    if(queue_empty(queue)) {
        printf("queue is empty");
        return;
    }
    queue->front = (queue->front + 1) % MAXSIZE;
}





