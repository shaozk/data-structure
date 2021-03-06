//
// Created by shaozk on 2021/3/6.
//

#include "include/SqList.h"
#include "include/LinkList.h"
#include "utils/print.h"

/**
 * 顺序表的合并
 */
Status MergeSqList(SqList *La, SqList* Lb, SqList *Lc) {
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
Status MergeLinkList(LinkList La, LinkList Lb, LinkList Lc) {

    return TRUE;
}

int main(){

    ElemType aArr[5] = {1,3,5,7,9};
    ElemType bArr[5] = {2,4,6,8,10};
    ElemType dArr[6] = {0,2,3,4,8,10};
    ElemType eArr[6] = {1,5,6,7,9,11};
    // 顺序表初始化
    SqList *La = InitSqList(), *Lb = InitSqList(), *Lc = InitSqList();
    for(int i = 0; i < 5; i++) {
        La->data[i] = aArr[i]; La->length++;
        Lb->data[i] = bArr[i]; Lb->length++;
    }
    Print("\n--init sq list--\n");
    Print("a"); PrintSqList(La);
    Print("b"); PrintSqList(Lb);

    // 顺序表合并
    Print("\n--merge sq list--\n");
    MergeSqList(La, Lb, Lc);
    printf("c"); PrintSqList(Lc);

    // 单链表初始化


    // 单链表合并


    return 0;
}