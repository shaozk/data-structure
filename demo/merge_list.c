/*****************************************************************************
 *
 * Name: merge_list.c
 * Date: 2021/3/8
 * Author: shaozk <https://github.com/shaozk>
 *
 *****************************************************************************/

#include "include/sq_list.h"
#include "include/link_list.h"

/**
 * 顺序表的合并
 */
Status Mergesq_list(sq_list *La, sq_list* Lb, sq_list *Lc) {
     int i = 0, j = 0, k = 0;
     while(i < La->length && j < Lb->length) {
         // 循环，比较两者大小
         if(La->data[i] < Lb->data[j]) {
           Lc->data[k++] = La->data[i++];
         } else {
            Lc->data[k++] = Lb->data[j++];
         }
     }

     while(i < La->length) {    // 还剩一个没有比较完的顺序表
         Lc->data[k++] = La->data[i++];
     }

     while(j < Lb->length) {
         Lc->data[k++] = Lb->data[j++];
     }
     // Lc的长度为La与Lb之和
     Lc->length = k;
     return TRUE;
}

/**
 * 单链表合并
 */
Status merge_list_link(link_list La, link_list Lb, link_list Lc) {

    return TRUE;
}

int main(){

    int aArr[5] = {1,3,5,7,9};
    int bArr[5] = {2,4,6,8,10};
    int dArr[6] = {0,2,3,4,8,10};
    int eArr[6] = {1,5,6,7,9,11};
    // 顺序表初始化
    sq_list *La = init_list_sq(), *Lb = init_list_sq(), *Lc = init_list_sq();
    for(int i = 0; i < 5; i++) {
        La->data[i] = aArr[i]; La->length++;
        Lb->data[i] = bArr[i]; Lb->length++;
    }
    printf("\n--init sq list--\n");
    printf("a"); print_list_sq(La);
    printf("b"); print_list_sq(Lb);

    // 顺序表合并
    printf("\n--merge sq list--\n");
    Mergesq_list(La, Lb, Lc);
    printf("c"); print_list_sq(Lc);

    // 单链表初始化
    link_list Ld = init_list_link(dArr, 6), Le = init_list_link(eArr, 6), Lf;
    printf("\n--init link list--\n");
    printf("d"); print_list_link(Ld);
    printf("e"); print_list_link(Le);

    // 单链表合并


    return 0;
}