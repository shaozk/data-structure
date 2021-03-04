/*顺序表*/
#include<stdio.h>
#include<stdlib.h>  // malloc() exit()

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 10
// 宏定义bool类型
#define BOOL int
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;
typedef struct {
    int *head;
    int length;
}SqList;

// 判断是否溢出函数
BOOL isOverflow(SqList *list, int i) {
    if(i < 0 || i > list->length) return FALSE;
    return TRUE;
}

// 顺序表的初始化
SqList* InitList(SqList *list) {
    // 构造一个空的顺序表
    SqList sqList;
    sqList.head = (int*)malloc(MAXSIZE * sizeof(int));
    if(!sqList.head) {
        printf("init error!");
        exit(0);
    }
    sqList.length = 0;
    return list;
}

// 顺序表的取值
Status GetElement(SqList *list, int i, ElemType e) {
    // 判溢出
    if(isOverflow(list, i) == FALSE) return ERROR;
    e = list->head[i-1];
    return OK;
}

// 顺序表的查找
int LocateElement(SqList *list, ElemType e) {
    int i;
    for(i = 0; i < list->length; i++) {
        if(e == list->head[i]) return i+1;
    }
    return 0;
}


// 顺序表的插入
void ListInsert(SqList *list, int ind, ElemType elem) {
    if(ind < 0 || ind > list->length) printf("%d\n",ERROR);
    if(list->length == MAXSIZE) printf("%d\n",ERROR);
    int i;
    for(i = list->length - 1; i >= ind-1; i--) {
        list->head[i+1] = list->head[i];
    }
    list->head[ind-1] = elem;
    list->length++;
}

// 顺序表的删除
void ListDelete(SqList *list, int ind) {
    if(ind < 0 || ind > list->length) printf("%d\n",ERROR);
    int j;
    for(j = ind; j < list->length; j++) {
        list->head[j] = list->head[j];
    }
    list->length--;
}

// 输出顺序表中的元素
void showSqList(SqList *list) {
    int i;
    for(i = 0; i < list->length; i++) {
        printf("%d ", list->head[i]);
    }
    printf("\n");
}


void main() {
    SqList *list = InitList(list);
    // 向顺序表中添加元素
    int i;
    for(i = 0; i < MAXSIZE; i++) {
        list->head[i] = i;
        list->length++;
    }
    ListDelete(list, 2);
    showSqList(list);
    ListInsert(list, 2, 5);
    // 显示顺序表中元素
    showSqList(list);

    
}
