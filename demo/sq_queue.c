/*****************************************************************************
 *
 * Name: sq_queue.c
 * Date: 2021/3/8
 * Author: shaozk <https://github.com/shaozk>
 *
 *****************************************************************************/

#include <sq_queue.h>

int main() {
    sq_queue *q = init_queue_sq();
    printf("%d %d %d\n", q->front, q->rear, q->size);

    printf("queue length:\t%d\n",queue_length_sq(q));

    for(int i = 0; i < 10; i ++) {
        en_queue_sq(q, i + 1);
    }
    printf("%d\n", q->size);

    de_queue_sq(q);
    printf("%d\n", q->size);




}
