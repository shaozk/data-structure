/*****************************************************************************
 *
 * Name: 3_huffman_coding.c
 * Date: 2021/4/14
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 假设用于通信的电文由n（4<n<30）个字符组成，字符在电文中出现的频度（权值）
 * 为w1，w2，……，试根据该权值序列构造哈夫曼树，并计算该树的带权路径长度。
 *
 * 输入格式：
 * 仅一组数据，分为两行输入：第1行为n的值，第2行为n个整数，表示字符的出现频度。
 *
 * 输出格式：
 * 一个整数，表示所构造哈夫曼树的带权路径长度（输出整数后换行）。
 *
 * 输入样例：
 * 8
 * 7 19 2 6 32 3 21 10
 *
 * 输出样例：
 * 261
 *
 * TODO 答案错误！！！
 *
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct btree_node {
    int weight;
    struct btree_node *left;
    struct btree_node *right;
}tree_node, *tree;

void find_min(tree *ht, const int len, int *i, int *j)
{ //寻找权值最小的两个节点
    int min, second_min;
    min = 0;
    // 1.找到权值最小结点
    for (int k = 1; k < len; k++) {
        if (ht[k]->weight < ht[min]->weight) {
            min = k;
        }
    }

    // 2.找到权值第二小结点
    // 如果第一个结点就是权值最小结点的话，权值第二小结点从第二个结点开始找起
    if (min == 0) {
        second_min = 1;
    }
    else {
        second_min = 0;
    }
    for (int k = 0; k < len; k++) {
        if (k != min && ht[k]->weight < ht[second_min]->weight) {
            second_min = k;
        }
    }
    *i = min > second_min ? second_min : min;
    *j = min > second_min ? min : second_min;
}

void merge_tree_node(tree *ht, int *len, int i, int j) {
    //合并树的节点
    if (*len <= 1)
        return;
    //生成合并后的节点
    tree tmp;
    tmp = (tree)malloc(sizeof(tree_node));
    tmp->weight = ht[i]->weight + ht[j]->weight;
    tmp->left = ht[i];
    tmp->right = ht[j];
    //在节点数组中删除原节点i
    for (int k = i; k < *len - 1; k++)
    {
        ht[k] = ht[k + 1];
    }
    (*len)--;
    //在节点数组中删除原节点j
    for (int k = j - 1; k < *len - 1; k++)
    {
        ht[k] = ht[k + 1];
    }
    (*len)--;
    //将合并后的节点存储起来
    ht[*len++] = tmp;
}

void traverse(tree ht, int deep, int *ans)
{ //递归遍历二叉树，累加计算带权路径长度
    if (ht == NULL)
        return;
    if (ht->left == NULL && ht->right == NULL)
    {
        *ans += ht->weight * deep;
    }
    traverse(ht->left, deep + 1, ans);
    traverse(ht->right, deep + 1, ans);
}

int main() {
    int n;
    scanf("%d", &n);
    tree ht[n]; // 结点数组
    int len = n;
    for (int i = 0; i < n; i++)
    {
        ht[i] = (tree)malloc(sizeof(tree_node));
        scanf("%d", &ht[i]->weight);
        ht[i]->left = NULL;
        ht[i]->right = NULL;
    }

    while (len > 1)
    { //数组中节点个数大于1时循环
        int i, j;
        find_min(ht, len, &i, &j);
        merge_tree_node(ht, &len, i, j);
    }
    int ans = 0;
    traverse(ht[0], 0, &ans);
    printf("%d\n", ans);
    return 0;
}
