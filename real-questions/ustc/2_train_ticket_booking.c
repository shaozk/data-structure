/*****************************************************************************
 *
 * Name: 2_train_ticket_booking.c
 * Date: 2021/3/13
 * Author: shaozk <https://github.com/shaozk>
 *
 * 火车票订票：火车经过X站，火车最大载客人数为m，有n个订票请求，请求订购从a站到
 * b站的k张票，若能满足订购要求则输出1，否则输出0。第一行有两个数，分别是n，m，
 * 接下来有n行，每行三个数分别为a，b，k
 *
 * 输入格式：
 *     第一行两个数，分别是n，m，接下来有n行，每行三个数分别是a，b，k
 *
 * 输出格式：
 *     满足订购要求输出1，否则输出0
 *
 * 输入样例：             输出样式：
 *     5 10                 1
 *     4 10 9               0
 *     8 12 2               1
 *     9 12 1               1
 *     14 20 8              0
 *     30 300 15
 *
 * 思路：
 * 采用数组表示订票，每三个单位表示一组订票（a,b,k）
 * 1）首站上车人数大于座位数，返回0，不载客，否则载客，并更新座位数
 * 2）第2站与第1站不存在交叉，能载客的总量为总人数，否则，载客量为总人数减去第一站人数
 *
 *****************************************************************************/

#include <stdio.h>

void train_ticket_booking(const int *arr, int n, int m) {
    int count = n / 3;  // 订票次数
    int k[count];   // 存放上车人数
    for(int i = 0; i < count; i++)
        k[i] = arr[i * 3 + 2];
    int i = 0, restNum = m; // 车上剩余座位数
    while(count > 0) {
        // 首站订票
        if(i == 0 && k[i] >m) { // 订票数大于座位数
            printf("0\n");
            restNum = m;    // 不载客人
            count--;i++;
            continue;
        } else if(i == 0) { // 订票数不大于作为数，可订购
            printf("1\n");
            restNum = m - k[i];
            count--;i++;
            continue;
        }
        // 后面站台订票
        if(arr[i * 3] > arr[3 * i - 2]) {   // 不存在交叉点
            for(int j = 0; j < i; j++)
                restNum += k[i];
            if(restNum > m)
                restNum = m;
            if(k[i] > restNum) {
                printf("0\n");
                count--;i++;
                continue;
            } else {
                printf("1\n");
                restNum -= k[i];
                count--;i++;
                continue;
            }

        } else {    // 存在交叉点
            if(k[i] > restNum) {
                printf("0\n");
                count--;i++;
                continue;
            } else {
                printf("1\n");
                restNum -= k[i];
                count--;i++;
                continue;
            }
        }
    }
}

int main() {
    int n = 5, m = 10;
    scanf("%d %d", &n, &m);
    int arr[n * 3];
    for(int i = 0; i < n * 3; i++) {
        scanf("%d",&arr[i]);
    }
    train_ticket_booking(arr, n * 3, m);
    return 0;
}