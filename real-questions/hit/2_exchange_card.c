/*****************************************************************************
 *
 * Name: 2_exchange_card.c
 * Date: 2021/4/12
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 1-20号牌，输入牌的数目，以及每张牌的编号。只有三张连续的牌可以兑换一张新牌，
 * 新牌不能参与兑换。编程实现计算可兑换的牌数。
 *
 * 输入格式：
 * 牌的数目
 * 输入牌的编号
 *
 * 输出格式：
 * 能兑换的牌的数量
 *
 * 输入样例：
 * 10
 * 1 1 2 2 3 5 5 6 7 9
 *
 * 输出样例：
 * 2
 *
 * 思路：
 * 设立一个数组，用于存放1-20牌的数量，其中下标为牌号，数组内容为牌数。
 * 每交换一次牌，牌数减1.
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int exchange_card(int *card, int n) {
    int num = 0, s = 0;
    while(s < (n - 2)) {
        if((card[s] >= 1) && (card[s+1] >= 1) && (card[s+2] >= 1)) {
            // 交换一个次牌，牌数减1
            card[s]-=1;
            card[s+1]--;
            card[s+2]--;
            num++;
        } else {
            s++;
        }
    }
    return num;
}

int main() {
    int n, *arr;
    int card[20];   // 用户存放各种卡的数目
    // 初始化牌数
    for(int i = 0; i < 20; i++) {
        card[i] = 0;
    }
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        card[arr[i] - 1]++;
    }
   printf("%d\n", exchange_card(card, n));
    return 0;
}