/*****************************************************************************
 *
 * Name: 4_is_absolute_prime.c
 * Date: 2021/4/4
 * Author: shaozk <https://github.com/shaozk>
 *
 * 西北大学上机题（四）
 * 是不是绝对素数？
 * 绝对素数是指本身是素数，其逆序也是素数的数，例如：107与701是绝对素数。
 * 求[m,n]范围之内的所有绝对素数。
 *
 * 输入格式：
 * 输入两个正整数m和n，其中m<n
 *
 * 输出格式：
 * 输出[m,n]之间的绝对素数
 *
 * 输入样例：
 * 105 115
 *
 * 输出样例：
 * 107
 * 113
 *
 * 思路：
 * 1.判断是否是素数
 * 2.用栈来判断是否是绝对素数
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    bool result = true;
    for(int i = 2; i < sqrt(n); i++) {
        if(n % i == 0) {
            result = false;
            break;
        }
    }
    return result;
}

int reverse_number(int n) {
    // 如果该书小于10，直接返回
    if(n % 10 == n) {
        return n;
    }
    int result = 0;
    while(n / 10) {
        result = result * 10 + n % 10;
        n /= 10;
    }
    // 最后一个数还需加上
    result = result * 10 + n;
    return result;
}

void is_absolute_prime(int m, int n) {
    if(m >= n) {
        printf("m必须小于n");
        exit(-1);
    }
    for(int a = m; a <= n; a++) {
        if(is_prime(a)) {
            // 构造数的逆序
            if(is_prime(reverse_number(a))) {
                printf("%d\n", a);
            }

        }
    }
}

int main() {
    int m,n;
    scanf("%d %d",&m, &n);
    is_absolute_prime(m,n);

    return 0;
}