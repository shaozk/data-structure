/*****************************************************************************
 *
 * Name: sq_stack.c
 * Date: 2021/3/8
 * Author: shaozk <https://github.com/shaozk>
 *
 *****************************************************************************/

#include "include/sq_stack.h"

int main() {
    // 初始化顺序栈
    sq_stack *S = init_stack_sq();

    // 入栈
    for(int i = 0; i < 10; i++) {
        push_sq(S, i + 1);
    }
    print_stack_sq(S);

    // 出栈
    int e = pop_sq(S);
    printf("%d\n", e);
    print_stack_sq(S);


    // 溢出
    printf("%d", push_sq(S, 9));

    //
    return 0;
}
