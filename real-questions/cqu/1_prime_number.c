/*****************************************************************************
 *
 * Name: 1_prime_number.c
 * Date: 2021/3/15
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 计算100以内的素数之和
 *
 * 思路：
 * 先确定素数，再求和
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    // 1不是素数
    if(n == 1) return false;
    // 2是素数
    if(n == 2) return true;
    // 偶数不是素数
    if(n % 2 == 0) return false;
    // 判断余下奇数
    for(int i = 3; i < n; i+=2) {
        if(n % i == 0) return false;
    }
    return true;
}

int prime_number() {
    int num = 0;
    for(int i = 1; i < 100; i++) {
        num += is_prime(i) ? i : 0;
    }
    return num;
}


int main() {

     int num = prime_number();
     printf("%d\n", num);

    return 0;
}