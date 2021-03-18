/*****************************************************************************
 *
 * Name: 2_find_the_perfect_number.c
 * Date: 2021/3/18
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 找出1000之内的所有完数，并输出完数和它的所有真因子（一个数恰好等于他的因子之和，
 * 称为完数，例如：6=1+2+3）
 *
 * 输出样例：
 * 6 28 296
 *
 * 思路：
 * 找到一个数的所有真因子，求和
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_perfect_number(int n) {
    int s = (int)sqrt(n) + 1;
    int sum = 1;
    for(int i = 2; i < s; i++) {
        if(n % i == 0) {
            sum += i;
            sum += (n / i);
        }
    }
    if(sum == n) return true;
    return false;
}

int main() {
    for(int i = 2; i < 1000; i++) {
        if(is_perfect_number(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}
