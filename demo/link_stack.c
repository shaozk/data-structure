/*****************************************************************************
 *
 * Name: link_stack.c
 * Date: 2021/3/8
 * Author: shaozk <https://github.com/shaozk>
 *
 *****************************************************************************/

#include "include/link_stack.h"


int main() {
    link_stack S = init_stack_link();
    for(int i = 0; i < 10; i++) {
        push_stack(S, i + 1);
    }
    return 0;
}