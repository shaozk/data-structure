/*****************************************************************************
 *
 * Name: 8_legal_identifier.c
 * Date: 2021/4/9
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 合法标识符。
 * 输入一个字符串，判断其是否是C语言的合法标识符，标识符由字母、下划线、数字
 * 这三种类型组成，但开头必须是字母或下划线（不用判断是否和保留字相同）。
 *
 * 输入格式：
 * 每组输入数据是一个长度不超过50的字符串。
 *
 * 输出格式：
 * 对于每组输入数据，如果是C的合法标识符，请输出“yes”，否则，输出“no”。
 *
 * 输入样例：
 * 12ajf
 *
 * 输出样例：
 * no
 *
 * 思路：
 * 1.判断是否是数字
 * 2.判断是否是字符
 * 3.判断是否是下划线
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

bool is_number(char c) {
    // 检查是否是数字字符
    bool result = false;
    if(c >= '0' && c <= '9') result = true;
    return result;
}



bool is_character(char c) {
    // 检查是否是字母字符
    bool result = false;
    if(c > 'a' && c < 'z' || c > 'A' && c < 'Z') result = true;
    return result;
}
bool is_underline(char c) {
    // 检查是否是下划线
    bool result = false;
    if(c == '_') result = true;
    return result;
}

bool is_legal_identifier(char *s){
    // 判断是否是合法标识符
    bool result = true;
    if(!is_underline(s[0]) && !is_character(s[0])) return false;
    for(int i = 1; i < strlen(s); i++) {
        if (!is_underline(s[i]) && !is_character(s[i]) && !is_number(s[i]))
        {
            result = false;
            break;
        }
    }
    return result;
}

int main() {
    int size = 1024;
    char *buff = (char *) malloc(size);

    // read lines
    while (NULL != gets(buff)) {
        if (is_legal_identifier(buff)) {
            printf("yes\n");
        } else printf("no\n");
    }

    // free buff
    free(buff);

    return 0;
}
