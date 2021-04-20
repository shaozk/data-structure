/*****************************************************************************
 *
 * Name: 1_the_sum_of_numbers.c
 * Date: 2021/4/13
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 编写一个程序，从键盘输入n个非0整数（0<n<1000），将这n个数中各位数字取出来
 * 相加，并按照从小到大的次序一次输入这些数字和。例如，497的各位数字和为20（4+7+9），
 * 1069的各位数字和为16（1+0+6+9）。
 *
 * 输入格式：
 * 输入的整数之间以空格分给，输入为0时结束
 *
 * 输出格式：
 * 在一行上从小到大输出计算结果，整数之间用1个空格分隔开，最后换行
 *
 * 输入样例：
 * 497 1069 68 71 137 0
 *
 * 输出样例：
 * 8 11 14 16 20
 *
 * 思路：
 * TODO
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int the_sum_of_number(int a) {
    int sum = 0;
    if(a <= 0) {
        printf("number must be bigger than 0!!");
        exit(-1);
    } else if(a <= 10) return a;
    while(a) {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

int cmp (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

void sort_asc(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = the_sum_of_number(arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp);
}

void show(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    putchar('\n');
}

int main() {
    int n, data[1000], tmp = 0, len = 0;
    do{
        scanf("%d",&n);
        if (n == 0) break;
        data[tmp++]=n;
        len++;
    }while(1);
    sort_asc(data, len);
    show(data, len);

    return 0;
}
