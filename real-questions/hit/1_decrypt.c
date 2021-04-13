/*****************************************************************************
 *
 * Name: 1_decrypt.c
 * Date: 2021/4/12
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 解密--加密的算法是26个英文字母，向后移三位为秘闻（a加密为d，最后x->a,y->b,z->c）
 * 有大小写。输入秘闻，计算明文
 *
 * 输入格式：
 * 密文
 *
 * 输出格式：
 * 明文
 *
 * 输入样例：
 * An asdwa lijxa
 *
 * 输出样例：
 * Xk xpatx ifgux
 *
 * 思路：
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdbool.h>

bool is_character(const char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    else return false;

}

bool is_upper(const char c) {
    if(c >= 'A' && c <= 'Z')
        return true;
    else return false;
}

char decrypt(char c) {
    // 非字母直接返回，（如空格字符）
    if(!is_character(c))
        return c;
    char result;
    if(is_upper(c)) {
        // 大写字母处理
        result = (c - 'A' - 3 + 26) % 26 + 'A';
    } else {
        // 小写字母处理
        result = (c - 'a' - 3 + 26) % 26 + 'a';
    }
    return result;
}

int main() {
    int c;
    while((c = getchar()) != '\n') {
        printf("%c", decrypt(c));
    }
    return 0;
}