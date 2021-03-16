/*****************************************************************************
 *
 * Name: 3_shortest_path_minimum_cost.c
 * Date: 2021/3/14
 * Author: shaozk <https://github.com/shaozk>
 *
 * 3.中科大上机题改编
 * 给你n个点，m条无向边，每条边都有长度d和花费p，给你起点s和终点t，要求输出起点到终点的
 * 最短路径以及其花费，如果最短距离有多条路线，则输出花费最少的。
 *
 * 输入格式：
 *  输入n,m，点的编号是1~n，然后是m行，没行4个数 a,b,d,p，表示a和b之间有一条边，且其
 *  长度为d，花费为p。最后一行是两个数 s，t；起点s终点t。（1<n<=1000,-<m<=100000,s!=t）
 *
 * 输出格式：
 *  输出一行有两个数，最短路径及其花费。
 *
 * 输入样例：            输出样例：
 *  3 2                   9 11
 *  1 2 5 6
 *  2 3 4 5
 *  1 3
 *
 * 思路：
 *
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100

// 边表结点
typedef struct arc_node {
    int adj_vex;    // 邻接点
    int p;          // 长度
    int d;          // 花费
    struct arc_node *next_arc;  // 下一条邻接表的指针
}arc_node;

// 顶点表结点
typedef struct v_node {
    int data;
    arc_node *first_arc;
}v_node, adj_list[MaxVertexNum];

typedef struct {
    adj_list vertices;
    int vex_num;    // 图的顶点数目
    int arc_num;   // 图的边数目
}al_graph;      // 以邻接表存储的图类型

int main(){
    int n, m, s, t;   // n个点，m条边
    scanf("%d %d", &n, &m);
    int a[n], b[n], d[n], p[n];

    for(int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &d[i], &p[i]);
    }
    scanf("%d %d", &s, &t);

    al_graph *graph = (al_graph*)malloc(sizeof(al_graph));
    graph->arc_num = m;
    graph->vex_num = n;
    for(int j = 0; j < m; j++) {
        arc_node *anode = (arc_node*)malloc(sizeof(arc_node));
        anode->d = d[j];
        anode->p = p[j];
        anode->adj_vex = b[j];
        graph->vertices[j].first_arc->next_arc = NULL;
        anode->next_arc = graph->vertices[j].first_arc->next_arc;
//        graph->vertices[a[j]].first_arc = anode;
//        graph->vertices[a[j]].data = a[j];
//
//        arc_node *bnode = (arc_node*)malloc(sizeof(arc_node));
//        bnode->d = d[j];
//        bnode->p = p[j];
//        bnode->adj_vex = a[j];
//        bnode->next_arc = graph->vertices[b[j]].first_arc->next_arc;
//        graph->vertices[b[j]].first_arc = bnode;
//        graph->vertices[b[j]].data = a[j];
    }

    for(int k = 0; k < m; k++) {
        printf("%d ", graph->vertices[k].data);
    }
    printf("\n");

    for(int j = 0; j < m; j++) {
        printf("%d %d %d %d\n", a[j], b[j], d[j], p[j]);
    }
    printf("%d %d\n", s, t);





    return 0;
}


