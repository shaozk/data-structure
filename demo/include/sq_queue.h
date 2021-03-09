/*****************************************************************************
 *
 * Name: sq_queue.h
 * Date: 2021/3/8
 * Author: shaozk <https://github.com/shaozk>
 *
 * 队列的顺序存储表示和实现
 *
 *****************************************************************************/
#ifndef DATA_STRUCTURE_SQ_QUEUE_H
#define DATA_STRUCTURE_SQ_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct sq_queue {
    int data[MAXSIZE];
    int front;         // 记录队列头元素位置
    int rear;          // 记录队列尾元素位置
    int size;          // 存储数据元素个数
}sq_queue;

// 初始化队列
sq_queue* init_queue_sq() {
    sq_queue* q = (sq_queue*)malloc(sizeof(sq_queue));
    if(!q) {
        printf("error!!");
        exit(-1);
    }
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}

// 队列长度
int queue_length_sq(sq_queue *q) {
    return q->size;
}

// 入队
void en_queue_sq(sq_queue *q, int e) {
    if (q->size > MAXSIZE) {
        printf("队列已满\n");
        exit(-1);
    }
    q->rear++;
    q->size++;
    q->data[q->rear] = e;
}

// 出队
int de_queue_sq(sq_queue *q) {
    if (q->size <= 0) {
        printf("队空\n");
        exit(-1);
    }
    q->front++;
    q->size--;
    return q->data[q->front];
}

// 取队头元素
int front_sq(sq_queue *q) {
    return q->data[0];
}

// 取队尾元素


#endif //DATA_STRUCTURE_SQ_QUEUE_H
