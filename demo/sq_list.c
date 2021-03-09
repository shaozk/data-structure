/*****************************************************************************
 *
 * Name: sq-list.c
 * Date: 2021/3/8
 * Author: shaozk <https://github.com/shaozk>
 *
 *****************************************************************************/

#include "include\sq_list.h"

int main(){
    // 初始化数组
    sq_list *L = init_list_sq();
    printf("\n--init list--\n");
    // 输出数组长度
    print_list_sq(L);

    // 附加数据
    printf("\n--append data--\n");
    for(int i = 0; i < 10; i++) {
        append_list_sq(L, i + 1);
    }
    print_length_sq(L);
    print_list_sq(L);

    // 插入数据
    printf("\n--insert data--\n");
    insert_list_sq(L, 3, 99);
    print_length_sq(L);
    print_list_sq(L);

    // 查找数据
    printf("\n-- locate element --\n");
    int index = locate_list_sq(L, 99);
    printf("elem:\t%d\n",index);

    // 删除元素
    printf("\n-- delete sq list --\n");
    delete_list_sq(L, 2);
    print_length_sq(L);
    print_list_sq(L);

    // 修改元素
    printf("\n-- update sq list --\n");
    update_list_sq(L, 2, 110);
    print_length_sq(L);
    print_list_sq(L);

    // 清空顺序表
    printf("\n--clear sq list--\n");
    clear_list_sq(L);
    print_length_sq(L);
    print_list_sq(L);

    // 销毁
    printf("\n--destroy sq list--\n");
    destroy_list_sq(L);
    print_length_sq(L);
    print_list_sq(L);

    return 0;


}