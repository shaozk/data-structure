/*****************************************************************************
 *
 * Name: 3_infinite_series.c
 * Date: 2021/4/12
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 计算1!+2!+3!+...+n!的最后六位。已知n>=25时最后6位全为0；
 *
 * 输入格式：
 * 输入n
 *
 * 输出格式：
 * 输出计算结果
 *
 * 输入样例：
 * 32
 *
 * 输出样例：
 * 940313
 *
 * 思路：
 * 暴力法会溢出！！！
 * 手动模型加法，乘法运算，只计算后6位
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void factorial(int n, int *fac) {
    if(n < 0) {
        printf("error\n");
        exit(-1);
    }
    if(n >= 25) {
        for(int i = 0; i < 6; i++) {
            fac[i] = 0;
        }
    } else {
        // n用十位和个位树表示
        int low, high, tmp = 1;
        // 初始化fac
        for (int i = 0; i < 5; i++) {
            fac[i] = 0;
        }
        fac[5] = 1;
        int cf = 0;
        while (tmp <= n) {
            int result_low[6];  // 个位计算结果
            int result_high[6]; // 十位计算结果
            low = tmp % 10;
            high = (tmp / 10) % 10;
            cf = 0; // cf表示进位
            // 先乘个位
            for (int i = 5; i >= 0; i--) {
                int t;
                t = fac[i] * low + cf;
                if (t >= 10) {
                    cf = t / 10;
                    result_low[i] = t % 10;
                } else {
                    result_low[i] = t;
                    cf = 0;
                }
            }
            cf = 0; // 注意进位重新初始化为0
            // 再乘十位
            for (int i = 5; i >= 0; i--) {
                int t;
                t = fac[i] * high + cf;
                if (t >= 10) {
                    cf = t / 10;
                    result_high[i] = t % 10;
                } else {
                    result_high[i] = t;
                    cf = 0;
                }
            }
            // 个十位结果相加
            fac[5] = result_low[5];
            cf = 0; // 进位清0
            for (int i = 4; i >= 0; i--) {
                int t = result_low[i] + result_high[i + 1] + cf;
                if (t >= 10) {
                    cf = t / 10;
                    fac[i] = t % 10;
                } else {
                    cf = 0;
                    fac[i] = t;
                }
            }
            tmp++;
        }
    }
}

int sum_of_factorial(int n, int *result) {
    // 如果n>=25,令n=24
    if (n >= 25) {
        sum_of_factorial(24, result);
    } else {
        // 初始化结果
        for(int i = 0; i < 6; i++) {
            result[i] = 0;
        }
        int fac[6];
        int cf; // 进位
        int tmp = 1;    // tmp为1~n的常数
        while(tmp <= n) {
            cf = 0;
            factorial(tmp, fac);    // 求tmp的阶乘
            for(int i = 5; i >= 0; i--) {
                // 将tmp的阶乘存放至结果中
                int t;
                t = result[i] + fac[i] + cf;
                if(t >= 10) {
                    cf = t / 10;
                    result[i] = t % 10;
                } else {
                    cf = 0;
                    result[i] = t;
                }
            }
            tmp++;
        }
    }
    return 0;
}

int main() {
    int n, *arr;
    scanf("%d" , &n);
    sum_of_factorial(n, arr);
    for(int i = 0; i < 6; i++) {
        printf("%d", arr[i]);
    }

    return 0;
}