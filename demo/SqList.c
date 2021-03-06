#include "include\SqList.h"

int main(){
    // 初始化数组
    SqList *L = InitList();
    printf("\n--init list--\n");
    // 输出数组长度
    PrintLength(L);

    // 附加数据
    printf("\n--append data--\n");
    for(int i = 0; i < 10; i++) {
        AppendList(L, i + 1);
    }
    PrintLength(L);
    PrintList(L);

    // 插入数据
    printf("\n--insert data--\n");
    InsertList(L, 3, 99);
    PrintLength(L);
    PrintList(L);

    // 查找数据
    printf("\n-- locate element --\n");
    int index = LocateElem(L, 99);
    printf("elem:\t%d\n",index);

    // 删除元素
    printf("\n-- delete list --\n");
    DeleteList(L, 2);
    PrintLength(L);
    PrintList(L);

    // 修改元素
    printf("\n-- update list --\n");
    UpdateList(L, 2, 110);
    PrintLength(L);
    PrintList(L);

    // 清空顺序表
    printf("\n--clear list--\n");
    ClearList(L);
    PrintLength(L);
    PrintList(L);

    // 销毁
    printf("\n--destroy list--\n");
    DestroyList(L);
    PrintLength(L);
    PrintList(L);

    return 0;


}