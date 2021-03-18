/*****************************************************************************
 *
 * Name: 3_palindrome_number.c
 * Date: 2021/3/18
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 判断输入的整数是否回文，输入的数据在10-1000以内。“回文数”是一种数字，如98789，
 * 这个数正读和倒读一样，所以这个数字就是回文数。
 *
 * 输入格式：        输出格式：
 * 10-1000内的数    true或false
 *
 * 输入样例：        输出样例：
 * 121              true
 * 123              false
 *
 * 思路：
 * 1.如果是两位数，直接可以列出11，22，33，44，55，66，77，88，99
 * 2.如果是三位数，判断个位数和百位数是否相等
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdbool.h>

bool is_palindrome_number(int n) {
    int arr[9] = {11,22,33,44,55,66,77,88,99};
    for(int i = 0; i < 9; i++) {
        if(n == arr[i]) {
            return true;
        }
    }
    int h = n / 100;    // 数的百位
    int g = n % 10;     // 数的个位
    if(g == h) {
        return true;
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    if(is_palindrome_number(n)) {
        printf("true");
    } else {
        printf("false");
    }
    return 0;
}
