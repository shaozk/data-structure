#include "include\SqList.h"

void main(){
    ElemType arr[5] = {1,2,3,4,5};
    // 初始化数组
    SqList *L = InitList(arr, 5);
    printf("\n-- list init --\n");
    // 输出数组长度
    Length(L);
    
    // 输出数组
    PrintList(*L);
    
    // 插入数据
    printf("\n-- insert data --\n");
    InsertList(L, 2, 110);
    Length(L);
    PrintList(*L);

    // 查找数据
    printf("\n-- locate element --\n");
    int index = LocateElem(L, 110);
    printf("elem:\t%d\n",index);

    // 删除元素
    printf("\n-- delete list --\n");
    DeleteList(L, 2);
    Length(L);
    PrintList(*L);\

    // 修改元素
    printf("\n-- update list --\n");
    UpdateList(L, 2, 110);
    Length(L);
    PrintList(*L);


}