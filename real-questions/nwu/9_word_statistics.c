/*****************************************************************************
 *
 * Name: 9_word_statistics.c
 * Date: 2021/4/9
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 单词统计。
 * 给定一个字符串，请计算其中一共包含多少个单词（假设连续的非空格字母即为一个单词）。
 *
 * 输入格式：
 * 输入数据是一个长度为S（0<s<1000）的字符串，其中只包含字母和空格。0<s<1000）的字符串，其中只包含字母和空格。<>
 *
 * 输出格式：
 * 请输出给定字符串一共包含的单词数。
 *
 * 输入样例：
 * Welcome to NWU
 *
 * 输出样例：
 * 3
 *
 * 思路：
 *
 *
 *****************************************************************************/

#include <stdio.h>

int main() {
    int c, num = 1, tag = 1;
    while( (c=getchar()) != '\n' ) {//从控制台流中读取字符，直到按回车键结束
        if (c != ' ' && c != '\0') { //当前是非空格字符
            tag = 1;
        }
        else if (tag == 1) {
            //当前是空格字符，且前一个字符是非空格字符，即找到了一个单词
            num++;
            tag = 0;
        }
    }
    printf("%d\n", num);
}
