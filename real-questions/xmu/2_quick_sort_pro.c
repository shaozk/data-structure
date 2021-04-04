/*****************************************************************************
 *
 * Name: 2_quick_sort_pro.c
 * Date: 2021/3/24
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 实现快速排序的变种。主要改进在于我们以往的pivot总是选第一个或最后一个，而这里
 * 需要我们选择是随机的一个。
 *
 * 输入格式：
 * 输入序列的长度
 * 输入序列中的元素
 *
 * 输出格式：
 * 排序后的结果
 *
 * 输入样例：
 * 10
 * 2 5 7 23 15 11 9 4 10 30
 *
 * 输出样例：
 * 2 4 5 7 9 10 11 15 23 30
 *
 *****************************************************************************/

#include <stdio.h>

int random_pivot(int A[], int low, int high) {
    int pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot) {
            --high;
        }
        A[low] = A[high];
        while (low < high && A[low] <= pivot) {
            ++low;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = random_pivot(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}


int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0 ;i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, 9);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


