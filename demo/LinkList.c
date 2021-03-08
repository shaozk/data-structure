//
// Created by shaozk on 2021/3/6.
//

#include<stdio.h>


#include "LinkList.h"
#include "../utils/print.h"




int main(){
    // 初始化链表
    Print("\n--init link list--\n");
    LinkList L = InitLinkList();
    PrintLinkList(L);

    // 插入元素
    Print("\n--insert link list--\n");
    InsertLinkList(L, 2, 99);
    PrintLinkList(L);

    // 删除元素
    Print("\n--delete link list--\n");
    DeleteLinkList(L, 2);
    PrintLinkList(L);

    // 查找结点的值
    Print("\n--locate link list--\n");
    ElemType e = LocateLinkList(L, 5);
    printf("elem:\t%d\n", e);



    return 0;
}
