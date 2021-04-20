/*****************************************************************************
 *
 * Name: 2_saddle_point.c
 * Date: 2021/4/13
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目:
 * 请写一个程序，找出给定矩阵的马鞍点。若一个矩阵中的元素在其所在行最小而在其列最大，
 * 则该元素为矩阵的一个马鞍点。
 *
 * 输入格式：
 * 输入数据由m+1行构成，第一行只有两个整数m和n（0<m<100,0<n<100），分别表示矩阵
 * 的行数和列数，接下来m行，每行n个整数表示矩阵元素（矩阵中的元素互不相同），整数之
 * 间以空格分隔。
 *
 * 输出格式：
 * 在一行上输出马鞍点的行号、列号（行号和列号从0开始计数）及元素的值（用一个空格分隔），
 * 之后换行；若不存在马鞍点，则输出一个字符串“no”后换行。
 *
 * 输入样例：
 * 4 3
 * 11 13 121
 * 407 72 88
 * 23 58 1
 * 134 30 62
 *
 * 输出样例：
 * 1 1 72
 *
 * 思路：
 * TODO
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdbool.h>

bool is_row_min(int mat[100][100], int n, int k, int q) {
    for(int j = 0; j < n; j++) {
        if (j != q && mat[k][j] < mat[k][q]) {
            return false;
        }
    }
    return true;
}

bool is_col_max(int mat[100][100], int m, int k, int q) {
    for(int i = 0; i < m; i++) {
        if(i != k && mat[i][q] > mat[k][q]) {
            return false;
        }
    }
    return true;
}
int main() {
    int n, m, mat[100][100];
    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(is_row_min(mat, n, i, j) && is_col_max(mat, m, i, j)) {
                printf("%d %d %d\n", i, j, mat[i][j]);
            }
        }
    }
    printf("你好");
    return 0;
}