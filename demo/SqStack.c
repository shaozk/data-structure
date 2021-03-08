//
// Created by shaozk on 2021/3/8.
//

#include "include/SqStack.h"

int main() {
    // 初始化顺序栈
    SqStack *S = InitSqLStack();

    // 入栈
    for(int i = 0; i < 10; i++) {
        SqPush(S, i + 1);
    }
    PrintSqStack(S);

    // 出栈
    SElemType e = SqPop(S);
    printf("%d\n", e);
    PrintSqStack(S);


    // 溢出
    printf("%d", SqPush(S, 9));

    //
    return 0;
}
