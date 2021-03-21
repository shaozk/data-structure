/*****************************************************************************
 *
 * Name: s_string.h
 * Date: 2021/3/21
 * Author: shaozk <https://github.com/shaozk>
 *
 * 串的定长顺序存储结构
 *
 *****************************************************************************/
#ifndef DATA_STRUCTURE_S_STRING_H
#define DATA_STRUCTURE_S_STRING_H

#include <string.h>
#include <stdbool.h>

#define MAXSIZE 100     // 串的最大长度

typedef struct{
    char ch[MAXSIZE];   // 存储串的一维数组
    int length;         // 串的当前长度
}s_string;

/*
 * 初始条件：chars是字符串常量
 * 操作结果：生成一个其值等于chars的串
 */
s_string* str_assign(const char *chars) {
    unsigned int len;
    s_string *string = NULL;
    len = strlen(chars);
    if (len > MAXSIZE) return string;
    for(int i = 0; i < len; i++) {
        string->ch[i] = chars[i];
    }
    return string;
}

/*
 * 初始条件：串str存在
 * 操作结果：由串str复制得一个新串
 */
s_string* str_copy(s_string *str)

// 串清空
s_string* clear_string(s_string *string) {
    string->length = 0;
    return string;
}

// 判空
bool is_empty(s_string *string) {
    return string->length == 0 ? true : false;
}

// 计数
int count(s_string *string) {
    return string->length;
}

// 求子串
s_string* sub_string(s_string *string, int pos, int len) {

}

// 查找

// 删除

// 比较

// 替换

// 串联接




#endif //DATA_STRUCTURE_S_STRING_H
