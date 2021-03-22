/*****************************************************************************
 *
 * Name: 2_find_max_min.c
 * Date: 2021/3/22
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 输入一组学生的成绩，以及一个给定区间，输出区间中的最高的学生排名和最低的学生排名。
 *
 * 输入格式：
 * 输入成绩的条数
 * 输入成绩(以空格隔开)
 * 输入要查询的区间【m n】
 *
 * 输出格式：
 * 输出最高排名和最低排名
 *
 * 输入样例：
 * 10
 * 75 82 67 88 90 56 43 95 70 32
 * 60 90
 *
 * 输出样例：
 * 2 7
 *
 *****************************************************************************/


#include <stdio.h>
#include <stdlib.h>

void find_max_min(const int *arr, int m, int n, int len) {
    if(len <= 0 || arr == NULL) return;
    int min, max;
    int min_rank = 1, max_rank = 1; // 排名，默认为一
    // 初始化 min，max
    for(int i = 0; i < len; i++) {
        if(arr[i] > m && arr[i] < n) {
            min = arr[i];
            max = arr[i];
            break;
        }
    }
    // 找到min，max
    for(int i = 0; i < len; i++) {
        if(arr[i] > n || arr[i] < m) {
            continue;
        } else {
            if(min > arr[i]) min = arr[i];
            if(max < arr[i]) max = arr[i];
        }
    }
    // 找到min，max与之相对应的排名
    for(int i = 0; i < len; i++) {
        if(arr[i] > max) {
            max_rank++;
        }
        if(arr[i] > min) {
            min_rank++;
        }
    }
    printf("%d %d\n", max_rank, min_rank);

}

int main() {
    int sum = 0, m = 0, n = 0, *arr;
    scanf("%d", &sum);
    arr = (int *)malloc(sizeof(int) * sum);
    for(int i = 0; i < sum; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d", &m, &n);
    find_max_min(arr, m, n, sum);

    return 0;
}
