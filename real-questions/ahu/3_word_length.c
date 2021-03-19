/*****************************************************************************
 *
 * Name: 3_word_length.c
 * Date: 2021/3/19
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 由键盘输入一行仅有英文字母及空格组成的字符，编程实现（相邻单词之间用一个空格
 * 或多个空格隔开）
 * （1）输出每个单词及其长度
 * （2）输出最长的单词
 *
 * 输入样例：
 * I am a boy
 *
 * 输出样例：
 * I    1
 * am   2
 * a    1
 * boy  3
 *
 * 思路：
 * 1.获取任意长度的字符串
 * 2.遍历字符串，判断字符是否为空
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int len = 10;   // 默认数组长度
    char *arr = NULL;
    int cnt = 0, count = 0, t;
    arr = (char *)malloc(len);
    while((t = getchar()) != '\n') {
        arr[cnt++] = t;
        if(cnt >= len - 1) {
            len += 10;
            arr = (char *)realloc(arr, len); // 不够，重新分配
        }
    }
    arr[cnt] = '\0'; // 数组末尾补零
    for(int i = 0; i < cnt; i++) {
        if(arr[i] != ' ') {
            printf("%c", arr[i]);
            count++;
        } else {
            printf("\t%d\n", count);
            count = 0;
        }
        if(i == cnt - 1) printf("\t%d\n", count);
    }
    free(arr);

    return 0;
}