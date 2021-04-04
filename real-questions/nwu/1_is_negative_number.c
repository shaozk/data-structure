/*****************************************************************************
 *
 * Name: 1_is_negative_number.c
 * Date: 2021/3/27
 * Author: shaozk <https://github.com/shaozk>
 *
 * 是不是正数？
 * 输入一个整数，如果这个数字大于0，则输出1，等于0，则输出0，小于0，则输出-1.
 *
 * 输入格式：
 * 每次输入一个整数
 *
 * 输出格式：
 * 输出1或0或-1
 *
 * 输入样例：
 * 34
 *
 * 输出样例：
 * 1
 *
 * 思路：
 * 不需要
 *
 *****************************************************************************/

#include <stdio.h>

int is_negative_number(int n) {
    if (n > 0) {
        return 1;
    } else if(n < 0) {
        return -1;
    } else if(n == 0) {
        return 0;
    } else {
        printf("error");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", is_negative_number(n));
    return 0;
}