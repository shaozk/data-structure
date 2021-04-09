/*****************************************************************************
 *
 * Name: 3_number_of_prime.c
 * Date: 2021/4/4
 * Author: shaozk <https://github.com/shaozk>
 *
 * 西北大学上机题（三）
 * 给定若干个正整数，请判断素数的个数
 *
 * 输入格式：
 * N个大于1小于10000的整数
 *
 * 输出格式:
 * N个数中素数的个数
 *
 * 输入样例：
 * 5 3 4 8 9 11
 *
 * 输出样例：
 * 3
 *
 *****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
 * 判断是否是素数
 */
bool is_prime(int n) {
    int s = sqrt(n) + 1;
    bool result = true;
    if (n <= 1) return false;
    for(int i = 2; i < s; i++) {
        if (n % i == 0 ) {
            result = false;
        }
    }
    return result;
}

/*
 * 素数数量
 */
int number_of_prime(int *arr, int n) {
    int num = 0;
    for(int i = 0; i < n; i++) {
        if(is_prime(arr[i])) {
            num++;
        }
    }
    return num;
}

int main() {
    int ind = 0, total = 10, num, len, *arr;
    arr = (int *)malloc(sizeof(int) * total);
    while(1) {
        // 动态自动增长
        if(ind == total -1 ) {
            int *p_temp = NULL;
            total *= 2;
            p_temp = (int *)realloc(arr, total);
            if(p_temp == NULL)
            {
                printf("扩展表内存失败！");
                return 0;
            }
            arr = p_temp;
        }
        scanf("%d", &num);
        char c = getchar();
        arr[ind++] = num;
        if(c == '\n') {
            break;
        }
    }
    len = ind;  // 数组长度
    printf("%d\n", number_of_prime(arr, len));
    free(arr);


    return 0;

}