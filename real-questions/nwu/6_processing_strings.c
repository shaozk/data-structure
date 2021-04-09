/*****************************************************************************
 *
 * Name: 6_processing_strings.c
 * Date: 2021/4/9
 * Author: shaozk <https://github.com/shaozk>
 *
 * 字符串处理-1-字母a的个数
 *
 * 输入格式:
 * 一段不超过80个单词的字符串，统计其中有多少个a字母
 *
 * 输出格式：
 * 输出这段字符串a的个数
 *
 * 输入样例:
 * fave cad ecd ygaijj
 *
 * 输出样例：
 * 3
 *
 * 思路：
 * 暴力法
 *****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int count_char_a(char *arr) {
    int sum = 0;
    for(int i = 0; i < strlen(arr); i++) {
        if(arr[i] == 'a') sum++;
    }
    return sum;
}

int main() {
    int size = 1024;
    char* buff = (char*)malloc(size);

    // read lines
    while(NULL != gets(buff)){
        printf("%d\n", count_char_a(buff));
    }

    // free buff
    free(buff);
    return 0;

}
