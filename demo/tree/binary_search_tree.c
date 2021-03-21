/*****************************************************************************
 *
 * Name: binary_search_tree.c
 * Date: 2021/3/21
 * Author: shaozk <https://github.com/shaozk>
 *
 *****************************************************************************/

#include "binary_search_tree.h"

int main() {
    int a[] = {10, 5, 19, 4, 8, 13, 24};
    tree_node *tree = NULL;
    for(int i = 0; i < 7; i++) {
        tree = insert_tree(tree, a[i]);
    }
    tree_node *temp = NULL;
    temp = find_tree(tree, 13);
    if(temp != NULL) {
        printf("find:\t%d\n", temp->value);
    }
    temp = find_min(tree);
    if(temp != NULL) {
        printf("min:\t%d\n", temp->value);
    }
    printf("\npre order:\n");
    pre_order(tree);
    printf("\nin order:\n");
    in_order(tree);
    printf("\npost order:\n");
    post_order(tree);

    delete_node(tree, 13);
    delete_node(tree, 19);
    printf("\nafter delete 13 and 19:\n");
    pre_order(tree);

    return 0;
}
