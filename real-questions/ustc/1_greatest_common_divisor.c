/*****************************************************************************
 *
 * Name: 1_greatest_common_divisor.c
 * Date: 2021/3/13
 * Author: shaozk <https://github.com/shaozk>
 *
 * 问题：
 * 最大公约数：
 *     输入n个数，求出这n个数的最小值，最大值以及他们的最大公约数。
 * 输入格式：
 *     第一行输入n
 *     输入n个数（以空格隔开）
 * 输出格式：
 *     最小值 最大值 最大公约数
 * 输入样例：
 *     3
 *     4 6 8
 * 输出样例
 *     4 8 4
 *
 * 思路：
 * 最大最小值（略）
 * n = 2,直接求最大公约数
 * n > 2,先求数组头部两个数的最大公约数g，然后分别求数组后面的元素与g的最大公约数，
 * 直至遍历完整个数组
 *
 *
 *****************************************************************************/

#include <stdio.h>

int find_max(int *arr, int n) {
    int max = arr[0];
    for(int i = 0; i < n; i++) {
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

int find_min(int *arr, int n) {
    int min = arr[0];
    for(int i = 0; i < n; i++) {
        if(arr[i] < min) min = arr[i];
    }
    return min;
}

int gcd_(int a, int b) {
    if(a % b == 0) return b;
    else return gcd_(b, a%b);
}

int find_gcd(int *arr, int n) {
    int g = gcd_(arr[0], arr[1]);
    for(int i = 2; i < n; i++) {
        g = gcd_(g, arr[i]);
    }
    return g;
}

int main() {
    int n, min, max, gcd;
    int *arr;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    max = find_max(arr,n);
    min = find_min(arr,n);
    gcd = find_gcd(arr,n);
    printf("%d %d %d\n", max, min, gcd);
    return 0;

}