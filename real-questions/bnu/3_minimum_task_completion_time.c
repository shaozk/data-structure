/*****************************************************************************
 *
 * Name: 3_minimum_task_completion_time.c
 * Date: 2021/3/23
 * Author: shaozk <https://github.com/shaozk>
 *
 * 题目：
 * 输入一堆要完成的任务，每个任务有开始时间和要完成的时间，求把这些任务做完
 * 最快要多久。（任务在相同时间内进行不会冲突，时间的格式采用的是整数）
 *
 * 输入格式：
 * 输入任务的总数
 * 各个任务开始的时间和所需要的时间
 *
 * 输出格式：
 * 所需时间
 *
 * 输入样例：
 * 5
 * 2 10
 * 5 3
 * 4 9
 * 6 3
 * 7 7
 *
 * 输出样例：
 * 12
 *
 * 思路：
 * 找到各个任务的最早开始时间和最晚结束时间（开始时间+花费时间），计算最晚结束
 * 时间和最早开始时间的差值
 *
 *****************************************************************************/

#include <stdio.h>

typedef struct task {
    int start_time;
    int spend_time;
}task;

int time(int n, task *t) {
    int min = t[0].start_time;
    int max = t[0].start_time + t[0].spend_time;
    for(int i = 1; i < n; i++) {
        if (min > t[i].start_time) {
            min = t[i].start_time;
        }
        if(max < (t[i].start_time + t[i].spend_time)) {
            max = t[i].start_time + t[i].spend_time;
        }
    }
    return max - min;
}

int main(){
    int n;
    scanf("%d", &n);
    task t[n];
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &t[i].start_time, &t[i].spend_time);
    }
    printf("%d\n", time(n, t));
    return 0;
}
