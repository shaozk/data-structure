/*****************************************************************************
 *
 * Name: 1_find_string_from_id.c
 * Date: 2021/3/21
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 给出一系列字符串及其对应的id，要求找出某个字符串对应的id
 * 输入n+1行，第一行输入字符串个数，接下来输入n行，没行输入字符串及对应id。
 * 最后输入其中的一个字符串，输出该字符串对应的id
 *
 * 输入格式：
 * 数据的条数
 * 输入每条数据的字符串和对应的id
 * 要查询的字符串
 *
 * 输出格式：
 * 对应的id
 *
 * 输入样例：
 * 5
 * boring 5
 * interesting 8
 * hello 4
 * world 2
 * test 9
 * world
 *
 * 输出样例：
 * word对应的id是2
 *
 * 思路：
 * 1.暴力法
 * 遍历判断字符串是否匹配
 * 2.
 *
 *****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void brute() {
    int n = 0, *id_arr, len = 10;
    char *str_arr[10] = {}, *str = NULL;
    scanf("%d", &n);
    id_arr = (int *)malloc(sizeof(int) * n);
//    if (n > 10) {
//        *str_arr = (char*)malloc(sizeof(str_arr) * n);
//    }
    for(int i = 0; i < n; i++) {
        str_arr[i] = (char*)malloc(sizeof(char) * n);
    }
    str = (char*)malloc(sizeof(char) * len);
    for(int i = 0; i < n; i++) {
        scanf("%s %d", str_arr[i], &id_arr[i]);
    }
    scanf("%s", str);
    for(int i = 0; i < n; i++) {
        if(strcmp(str,str_arr[i]) == 0) {
            printf("%s %d\n", str, id_arr[i]);
        }
    }
}

int main() {
    brute();
    return 0;
}
