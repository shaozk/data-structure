//
// Created by shaozk on 2021/3/6.
//

/*单链表*/

#define ElemType int

// 单链表的存储结构
typedef struct LNode {
    ElemType data;          // 结点的数据域
    struct LNode *next;     // 结点的指针域
}LNode, *LinkList;      // LinkList为指向结构体LNode的指针类型

// 获取链表长度
int GetLinkLength(LinkList L);

// 输出链表长度
void PrintLinkLength(LinkList L);

// 链表显示
void PrintLinkList(LinkList L);

// 初始化(包含头指针的单链表)
LinkList InitLinkList();

// 插入元素
LinkList InsertLinkList(LinkList L, int i, ElemType e);

// 删除元素
LinkList DeleteLinkList(LinkList L, int i);

// 查找结点的值
ElemType LocateLinkList(LinkList L, int i);






