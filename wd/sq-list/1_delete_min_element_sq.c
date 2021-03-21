/*****************************************************************************
 *
 * Name: delete_min_element_sq.c
 * Date: 2021/3/9
 * Author: shaozk <https://github.com/shaozk>
 *
 * 问题：
 * 1.从顺序表中删除具有最小值的元素（假设唯一）并有函数所给返回被删除元素的值。空出
 * 的位置又最后一个元素填补，若顺序表为空，则显示出错误信息并退出运行。
 *
 * 思路：
 * 1.遍历顺序表
 * 2.查找最小元素并记录其下标
 * 3.遍历结束后用最后一个元素填补
 *
 *****************************************************************************/


#include <init_sq_list.h>

// 删除顺序表中最小值
int delete_min_element_sq(sq_list *list) {
    if(list->length == 0) {
        printf("error!!Sequence table cannot be empty\n");
        return -1;
    }
    int min = list->data[0];    // 保存最小值
    int len = list->length;     // 顺序表长度
    int ind = 0;                // 记录最小值下标
    for(int i = 1; i < len; i++) {
        if(list->data[i] < min) {
            min = list->data[i];
            ind = i;
        }
    }
    list->data[ind] = list->data[len - 1];
    list->length--;
    return min;
}

int main() {
    // 测试
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    sq_list *list = init_list_from_array_sq(arr, 10);
    print_length_sq(list);
    print_list_sq(list);
    for(int j = 0; j < 10; j++) {
        int min_element = delete_min_element_sq(list);
        printf("%d\n", min_element);
        print_length_sq(list);
        print_list_sq(list);
    }
}