/*****************************************************************************
 *
 * Name: seq_list.h
 * Date: 2021/3/9
 * Author: shaozk <https://github.com/shaozk>
 *
 * 动态分配数组顺序表
 *
 *****************************************************************************/
#ifndef DATA_STRUCTURE_SEQ_LIST_H
#define DATA_STRUCTURE_SEQ_LIST_H

#define InitSize 100    // 表的初始长度

typedef struct {
    int *data;      // 指向动态分配数组的指针
    int maxsize;    // 数组最大容量
    int length;     // 数组当前大小
}seq_list;      // 动态分配数组顺序表类型

// 插入
insert_list_seq() {

}



#endif //DATA_STRUCTURE_SEQ_LIST_H
