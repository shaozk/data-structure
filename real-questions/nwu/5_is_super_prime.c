/*****************************************************************************
 *
 * Name: 5_is_super_prime.c
 * Date: 2021/4/9
 * Author: shaozk <https://github.com/shaozk>
 *
 * 是不是超素数？
 * 如果一个数是素数，并且能被分解为C（C>=2）个连续素数的和，则称
 * 这个数为“超素数”，请编程判断一个数是否是超素数。
 *
 * 输入格式：
 * 一个正整数N（1<N<100000）
 *
 * 输出格式：
 * 给定的整数N为超素数，请输入yes，否则请输出no
 *
 * 输入样例：
 * 5
 *
 * 输出样例：
 * yes
 *
 *****************************************************************************/


#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX_LENGTH 100000

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

int sum_of_arr(int *arr, int p, int q) {
    int sum = 0;
    for(int i = p; i < q; i++) {
        sum += arr[i];
    }
    return sum;

}

bool is_super_prime(int n) {
    if(!is_prime(n)) {
        return false;
    }
    bool result = true;
    int prime_arr[MAX_LENGTH]; // 存放素数序列
    int length = 0;             // 保存素数序列长度
    for (int i = 2; i < n; i++) {
        // 找出所有小于num的素数，存入prime_arr中
        if (is_prime(i)) {
            prime_arr[length] = i;
            length++;
        }
    }
    // 从这些素数的子序列中寻找和等于n的子序列
    int p = 0, q = length - 1;   // 定义头尾指针，
    while(p < q) {
        // 尝试找出和为n的子序列
        int sum = sum_of_arr(prime_arr, p, q);
        // 和小，p后移
        if(sum < n) {
            p++;

        } else if(sum > n) { // 和大，q前移
            q--;
        } else {
            // 找到子序列
            break;
        }


    }
    if (p == q) {
        //检查是否是找到子序列而跳出循环的
        result = false;
    }
    return result;
}



int main() {
    int n;
//    printf("%d\n", is_prime(5));
    if(is_super_prime(5)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}
