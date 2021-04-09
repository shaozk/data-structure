/*****************************************************************************
 *
 * Name: 2_is_prime_number.c
 * Date: 2021/3/27
 * Author: shaozk <https://github.com/shaozk>
 *
 * 给定一个正整数，判断是否为素数（除了1和本身，没有其他约数的数称为素数）
 *
 * 输入格式：
 * 输入整数n
 *
 * 输出格式：
 * yew或no
 *
 * 输入样例
 * 23
 *
 * 输出样例
 * yes
 *
 *****************************************************************************/

#include <stdio.h>
#include <math.h>

void is_prime_number(int n) {
    int s = sqrtl(n) + 1, flag = 0;
    if (n <= 1) flag = 1;
    else {
        for(int i = 2; i < s; i++) {
            if (n % i == 0 ) {
                flag = 1;
            }
        }
    }
    if(flag == 1) printf("no");
    else printf("yes");
}

int main() {
    int n;
    scanf("%d", &n);
    is_prime_number(n);
    return 0;
}
