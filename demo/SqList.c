#include "include\SqList.h"

int main(){
    // 初始化数组
    SqList *L = InitSqList();
    printf("\n--init list--\n");
    // 输出数组长度
    PrintSqLength(L);

    // 附加数据
    printf("\n--append data--\n");
    for(int i = 0; i < 10; i++) {
        AppendSqList(L, i + 1);
    }
    PrintSqLength(L);
    PrintSqList(L);

    // 插入数据
    printf("\n--insert data--\n");
    InsertSqList(L, 3, 99);
    PrintSqLength(L);
    PrintSqList(L);

    // 查找数据
    printf("\n-- locate element --\n");
    int index = LocateSqList(L, 99);
    printf("elem:\t%d\n",index);

    // 删除元素
    printf("\n-- delete sq list --\n");
    DeleteSqList(L, 2);
    PrintSqLength(L);
    PrintSqList(L);

    // 修改元素
    printf("\n-- update sq list --\n");
    UpdateSqList(L, 2, 110);
    PrintSqLength(L);
    PrintSqList(L);

    // 清空顺序表
    printf("\n--clear sq list--\n");
    ClearSqList(L);
    PrintSqLength(L);
    PrintSqList(L);

    // 销毁
    printf("\n--destroy sq list--\n");
    DestroySqList(L);
    PrintSqLength(L);
    PrintSqList(L);

    return 0;


}