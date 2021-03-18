/*****************************************************************************
 *
 * Name: 1_odd_numbe_found.c
 * Date: 2021/3/18
 * Author: shaozk <https://github.com/shaozk>
 *
 * 问题：
 * 输入10个正整数（有奇数也有偶数），要求输出其中的每个奇数，并输出
 * 奇数个数和奇数之和。
 *
 * 输入格式：                输出格式：
 * 10个整数                  输出奇数
 *                          奇数的个数
 *                          奇数之和
 *
 * 输入样例：                输出样例：
 * 11 4 3 2 7 6 8 5 10 9      11 3 7 5 9
 *                          NUM=5
 *                          SUM=35
 *
 * 思路：
 * 遍历数组找到所有奇数
 *
 *****************************************************************************/

#include <stdio.h>

int main() {
    int arr[10], ind = 0, sum = 0;
    for(int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    for(int j = 0; j < 10; j++) {
        if(arr[j] % 2 == 1) {
            arr[ind++] = arr[j];
            sum+=arr[j];
        }
    }
    for(int k = 0; k < ind; k++) {
        printf("%d ",arr[k]);
    }
    printf("\nNUM=%d\n", ind);
    printf("SUM=%d\n", sum);
    return 0;
}