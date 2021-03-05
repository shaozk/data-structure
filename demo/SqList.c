/* 顺序表
数组类型：静态分配
*/
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

#define MAXSIZE 50     // 定义顺序表的最大元素个数
#define ElemType int   // 定义元素类型

typedef struct {
    ElemType data[MAXSIZE];     // 顺序表的元素
    int length;                 // 顺序表的当前长度
}SqList;                // 顺序表的类型定义

// 初始化顺序表
SqList* InitList(int *arr, int n) {
    if(n > MAXSIZE) printf("stack overflow");
    SqList *L;
    L->length = 0;       // 初始化顺序表长度
    for(int i = 0; i < n; i++) {
        L->data[i] = arr[i];
        L->length++;
    }
    return L;
}

// 插入
void InsertList(SqList *L, int i, ElemType e) {
    if(i < 0 || i > L->length) printf("error");
    if(i > MAXSIZE) printf("error");
    for(int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    L->length++;
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
void PrintList(SqList L) {
    printf("list:\t"); 
    for(int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

// 顺序表长度
void Length(SqList *L) {
        printf("length:\t%d\n", L->length);
}

// 输出数组
void PrintArr(ElemType *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

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