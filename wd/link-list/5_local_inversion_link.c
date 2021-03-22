/*****************************************************************************
 *
 * Name: 5_local_inversion_link.c
 * Date: 2021/3/22
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 5.试着编写算法将带头结点的单链表就地逆置，所谓”就地“，就是指辅助空间复杂度为O(1)
 *
 * 思路：
 * 1.头插法
 * 2.指针反转法
 *
 *****************************************************************************/

#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *next;
}node, *link_list;

/*
 * 头插法初始化
 */
link_list init_list(link_list list, int a) {
    if(list == NULL) {
        // 表头结点为空，新建表头结点
        node *head = (node*)malloc(sizeof(node));
        if(head == NULL) {
            printf("malloc failed");
        }
        head->next = NULL;
        list = head;
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
 * 就地置逆方法一
 * 利用头插法
 */
link_list local_inversion_one(link_list list) {
    node *p, *r;
    p = list->next;         // 去掉头结点
    list->next = NULL;      // 清空原链表
    while(p != NULL) {
        r = p->next;    // 保存后继结点，以防断链
        p->next = list->next;
        list->next = p;
        p = r;
    }
    return list;
}

/*
 * 方法二
 * 指针反转法
 */
link_list local_inversion_two(link_list list) {
    node *pre, *p = list->next, *r = p->next;
    // 处理首结点（也就是逆置后的尾结点）
    p->next = NULL;
    while(r != NULL) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;  // 逆置
    }
    list->next = p; // 头结点指向反转后的链表
    return list;
}

int main(){
    int arr[5] = {1,2,3,4,5};
    link_list list = NULL;
    for(int i = 0; i < 5; i++) {
        list = init_list(list, arr[i]);
    }
    traverse_list(list->next);
    puts("");   // 换行
    list = local_inversion_one(list);
    traverse_list(list->next);
    puts("");
    list = local_inversion_two(list);
    traverse_list(list->next);
    return 0;
}
