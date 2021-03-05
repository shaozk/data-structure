/*
1）将两个递增的有序链表合并为一个递增的有序链表。要求结果链表仍使用原来两个链表的存储空间，
不另外占用其他的存储空间。表中不允许有重复的数据
*/
#include<stdlib.h>
#include<stdio.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

LinkList InitList(LinkList list, int arr[], int n) {
    LinkList head = (LNode*)malloc(sizeof(LNode));
    head->next = NULL;
    LNode *p = head;
    for(int i = 0; i < n; i++) {
        LNode *node=(LNode*)malloc(sizeof(LNode));
        node->data=arr[i];
        node->next=NULL;
        p->next=node;
        p=p->next;
    }
    return head;
}

void showList(LinkList list) {
    while(list->next) {
        printf("%d ", list->next->data);
        list = list->next;
    }
    printf("\n");
}

void showArr(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main(){
    LinkList l1, l2;
    int a1[] = {1,3,5,7,9}, a2[] = {2,4,5,6,8};
    l1 = InitList(l1, a1, 5);
    l2 = InitList(l2, a2, 5);
    showArr(a1, 5);
    showArr(a2, 5);
    showList(l1);
    showList(l2);
}
