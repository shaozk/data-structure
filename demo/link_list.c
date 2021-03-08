//
// Created by shaozk on 2021/3/6.
//

#include <stdio.h>
#include <link_list.h>

int main(){
    // 初始化链表
    printf("\n--init link list--\n");
    link_list L = init_list_link();
    print_list_link(L);

    // 插入元素
    printf("\n--insert link list--\n");
    insert_list_link(L, 2, 99);
    print_list_link(L);

    // 删除元素
    printf("\n--delete link list--\n");
    delete_list_link(L, 2);
    print_list_link(L);

    // 查找结点的值
    printf("\n--locate link list--\n");
    int e = locate_list_link(L, 5);
    printf("elem:\t%d\n", e);

    return 0;
}
