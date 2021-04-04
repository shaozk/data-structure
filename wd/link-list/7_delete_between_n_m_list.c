/*****************************************************************************
 *
 * Name: 7_delete_between_n_m_list.c
 * Date: 2021/3/22
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 7.设在一个代表头结点的单链表中所有元素结点的数据值无序，试编写一个函数，删除表中所有
 * 介于给定的两个值（作为函数参数给出）之间的元素的元素（若存在）
 *
 * 思路：
 * 因为链表无序，只能一个个访问判断。
 * 注意在删除结点的时候要防止断链
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node, *link_list;

/*
 * 头插法初始化链表
 */
link_list init_list(link_list list, int a) {
    if(list == NULL) {
        list = (node*)malloc(sizeof(node));
        if(list == NULL) {
            printf("malloc failed");
            return NULL;
        }
        list->next = NULL;
    }
    node *temp = (node*)malloc(sizeof(node));
    temp->data = a;
    temp->next = list->next;
    list->next = temp;
    return list;

}

/*
 * 输出链表
 */
void traverse_list(link_list list) {
    if(list == NULL) return;
    traverse_list(list->next);
    printf("%d ", list->data);
}

/*
 * 循环输出链表
 */
void printf_list(link_list list) {
    node *p = list->next;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

/*
 * 删除介于m，n之间的元素
 */
link_list delete_list_m_n(link_list list, int m, int n) {
    node *pre = list, *p = list->next;
    while(p != NULL) {
        if(p->data > m && p->data < n) {
            // 删除该结点
            node *temp = p;
            p = p->next;
            pre->next = p;
            free(temp);
        } else {
            pre = p;
            p = p->next;
        }
    }
    return list;
}

int main(){
    int m, n;
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    scanf("%d %d", &m, &n);
    link_list list = NULL;
    for(int i = 0; i < 10; i++) {
        list = init_list(list, arr[i]);
    }
    list = delete_list_m_n(list, m, n);
    traverse_list(list->next);


    return 0;
}
