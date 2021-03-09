/*****************************************************************************
 *
 * Name: sq-list.h
 * Date: 2021/3/8
 * Author: shaozk <https://github.com/shaozk>
 *
 *****************************************************************************/


/* 顺序表
数组类型：静态分配
*/
#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 50     // 定义顺序表的最大元素个数
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef struct {
    int data[MAXSIZE];     // 顺序表的元素
    int length;            // 顺序表的当前长度
}sq_list;                  // 顺序表的类型定义



// 初始化顺序表
sq_list* init_list_sq() {
    sq_list *l = (sq_list*)malloc(sizeof(sq_list));
    if(l == NULL) {
        printf("init malloc error!!!");
        exit(-1);
    }
    l->length = 0;       // 初始化顺序表长度
    return l;
}

// 附加元素操作
Status append_list_sq(sq_list *L, int e) {
    // 判断顺序表是否大于MAXSIZE,是则抛出动态增加容量
    if(L->length >= MAXSIZE) {
        return FALSE;
    }
    L->data[L->length] = e;
    L->length++;

    return TRUE;
}

// 插入
Status insert_list_sq(sq_list *L, int i, int e) {
    if(i > MAXSIZE) return FALSE;
    for(int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    L->length++;
    return TRUE;
}

// 查找
int locate_list_sq(sq_list *L, int e) {
    for(int i = 0; i < L->length; i++) {
        if(e == L->data[i]) {
            return i+1;
        }
    }
    return -1;  // -1表示没找到
}

// 删除
void delete_list_sq(sq_list *L, int i) {
    if(i < 0 || i > L->length) printf("error");
    for(int j = i - 1; j < L->length - 1; j++) {
        L->data[j] = L->data[j + 1];
    }
    L->length--;
    // return L->data[i - 1]; // 返回删除元素的值
}

// 修改
void update_list_sq(sq_list *L, int i, int e) {
    if(i < 0 || i > L->length) printf("error\n");
    L->data[i-1] = e;
}

// 输出顺序表
void print_list_sq(sq_list *L) {
    if(L->length == 0) {
        printf("Sequence table is empty\n");
    } else {
        printf("list:\t");
        for(int i = 0; i < L->length; i++) {
            printf("%d ", L->data[i]);
        }
        printf("\n");
    }

}

// 顺序表长度
void print_length_sq(sq_list *L) {
        printf("length:\t%d\n", L->length);
}

// 输出数组
void print_arr(int *arr, int n) {
    printf("arr:\t");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 判断顺序表是否为空
Status is_empty(sq_list *L) {
    return L->length == 0 ? TRUE : FALSE;
}

// 获取元素个数
int get_list_length_sq(sq_list *L) {
    return L->length;
}

// 清空顺序表
void clear_list_sq(sq_list *L) {
    L->length = 0;
}

// 销毁顺序表
void destroy_list_sq(sq_list *L) {
    free(L);
    L = NULL;
}
