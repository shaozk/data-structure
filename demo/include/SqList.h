/* 顺序表
数组类型：静态分配
*/
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

#define MAXSIZE 50     // 定义顺序表的最大元素个数
#define ElemType int   // 定义元素类型
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef struct {
    ElemType data[MAXSIZE];     // 顺序表的元素
    int length;                 // 顺序表的当前长度
}SqList;                // 顺序表的类型定义



// 初始化顺序表
SqList* InitList() {
    SqList *L = (SqList*)malloc(sizeof(SqList));
    if(L == NULL) {
        printf("init malloc error!!!");
        exit(-1);
    }
    L->length = 0;       // 初始化顺序表长度
    return L;
}

// 附加元素操作
Status AppendList(SqList *L, ElemType e) {
    // 判断顺序表是否大于MAXSIZE,是则抛出动态增加容量
    if(L->length >= MAXSIZE) {
        return FALSE;
    }
    L->data[L->length] = e;
    L->length++;

    return TRUE;
}

// 插入
Status InsertList(SqList *L, int i, ElemType e) {
    if(i > MAXSIZE) return FALSE;
    for(int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    L->length++;
    return TRUE;
}

// 查找
int LocateElem(SqList *L, ElemType e) {
    for(int i = 0; i < L->length; i++) {
        if(e == L->data[i]) {
            return i+1;
        }
    }
    return -1;  // -1表示没找到
}

// 删除
void DeleteList(SqList *L, int i) {
    if(i < 0 || i > L->length) printf("error");
    for(int j = i - 1; j < L->length - 1; j++) {
        L->data[j] = L->data[j + 1];
    }
    L->length--;
    // return L->data[i - 1]; // 返回删除元素的值
}

// 修改
void UpdateList(SqList *L, int i, ElemType e) {
    if(i < 0 || i > L->length) printf("error\n");
    L->data[i-1] = e;
}

// 输出顺序表
void PrintList(SqList *L) {
    printf("list:\t"); 
    for(int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

// 顺序表长度
void PrintLength(SqList *L) {
        printf("length:\t%d\n", L->length);
}

// 输出数组
void PrintArr(ElemType *arr, int n) {
    printf("arr:\t");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 判断顺序表是否为空
Status IsEmpty(SqList *L) {
    return L->length == 0 ? TRUE : FALSE;
}

// 获取元素个数
int GetLength(SqList *L) {
    return L->length;
}

// 清空顺序表
void ClearList(SqList *L) {
    L->length = 0;
}

// 销毁顺序表
void DestroyList(SqList *L) {
    free(L);
    L = NULL;
}
