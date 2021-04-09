/*****************************************************************************
 *
 * Name: 7_count_the_number_of_vowels.c
 * Date: 2021/4/9
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 统计每个元音字母在字符串中出现的次数。
 *
 * 输入格式：
 * 每组输入数据是一行长度不超过100的字符串。
 *
 * 输出格式：
 * 对于每个测试实例输出5行
 * 格式如下：a:num1 e:num2 i:num3 o:num4 u:num5
 *
 * 输入样例：
 * my name is ignatius
 *
 * 输出样例：
 * a:2
 * e:1
 * i:3
 * o:0
 * u:1
 *
 * 思路:
 * switch case
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void count_the_number_of_vowels(char *arr) {
    int a = 0, e = 0, _i = 0, o = 0, u = 0;
    for(int i = 0; i < strlen(arr); i++) {
        switch(arr[i]) {
            case 'a': a++; break;
            case 'e': e++; break;
            case 'i': _i++; break;
            case 'o': o++; break;
            case 'u': u++; break;
        }
    }
    printf("a:%d\n", a);
    printf("e:%d\n", e);
    printf("i:%d\n", _i);
    printf("o:%d\n", o);
    printf("u:%d\n", u);
}

int main() {
    int size = 1024;
    char* buff = (char*)malloc(size);

    // read lines
    while(NULL != gets(buff)){
        count_the_number_of_vowels(buff);
    }
    free(buff);
    return 0;
}
