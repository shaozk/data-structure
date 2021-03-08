//
// Created by shaozk on 2021/3/8.
//

#include "include/LinkStack.h"


int main() {
    LinkStack S = InitLinkStack();
    for(int i = 0; i < 10; i++) {
        LinkPush(S, i + 1);
    }
    PrintLinkStack(S);

    return 0;
}