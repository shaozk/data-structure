/*****************************************************************************
 *
 * Name: 2_upper_to_lower.c
 * Date: 2021/3/18
 * Author: shaozk <https://github.com/shaozk>
 *
 * 问题：
 * 键盘那输入任意的字符串，让字符串的大写字母变小写。
 *
 * 输入格式：            输出格式：
 * 字符串长度            转换后的字符串
 * 含大写的字符串
 *
 * 输入样例：            输出样例：
 * 5                    csgab
 * csGaB
 *
 * 思路：
 * 大写字母变小写字母 大-'A'+'a' = 小
 *
 *
 *****************************************************************************/

#include <stdio.h>

int main() {
    int n = 0;
    char arr[100];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%c", &arr[i]);
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] >= 'A' && arr[i] <= 'Z') {
            arr[i] = (char) (arr[i] - 'A' + 'a');
        }
    }
    printf("%s\n", arr);

    return 0;
}