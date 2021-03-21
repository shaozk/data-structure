/*****************************************************************************
 *
 * Name: binary_search_tree.h
 * Date: 2021/3/21
 * Author: shaozk <https://github.com/shaozk>
 *
 * 二分查找树
 * 1.插入
 * 2.删除结点
 * 3.找到最小结点
 * 4.找到结点
 * 5.前中后序遍历
 *
 *****************************************************************************/
#ifndef DATA_STRUCTURE_BINARY_SEARCH_TREE_H
#define DATA_STRUCTURE_BINARY_SEARCH_TREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct tree_node {
    int value;
    struct tree_node *left;     // 左孩子
    struct tree_node *right;    // 右孩子
}tree_node;

// 将value插入树中
tree_node* insert_tree(tree_node *tree, int value) {
    if(tree == NULL) {
        // 新建一个结点
        tree = (tree_node*)malloc(sizeof(tree_node));
        if(tree == NULL) {
            printf("malloc failed\n");
            return NULL;
        } else {
            // 将value存入该结点中
            printf("insert %d to tree\n", value);
            tree->value = value;
            tree->left = NULL;
            tree->right = NULL;
        }
    } else if(value < tree->value){
        // 比当前的结点值小，放左边
        tree->left = insert_tree(tree->left, value);
    } else if(value > tree->value) {
        // 比当前的结点值大，放右边
        tree->right = insert_tree(tree->right, value);

    }
    return tree;

}

// 查找值为value的结点
tree_node* find_tree(tree_node *tree, int value) {
    if(tree == NULL) {
        // 没有找到
        return NULL;
    }
    // 在左子树查找
    if (value < tree->value) {
        return find_tree(tree->left, value);
    } else if (value > tree->value) {
        // 在右子树查找
        return find_tree(tree->right, value);
    } else {
        // 找到结点
        return tree;
    }
}

// 找到一棵树中最小的结点
tree_node* find_min(tree_node *tree) {
    if(tree == NULL) {
        return NULL;
    } else if(tree->left == NULL) {
        return tree;
    } else return find_min(tree->left);
}

// 删除结点
tree_node* delete_node(tree_node *tree, int value) {
    tree_node *temp_node = NULL;
    if(tree == NULL) {
        return NULL;
    } else if(value < tree->value) {
        tree->left = delete_node(tree->left, value);
    } else if(value > tree->value) {
        tree->right = delete_node(tree->right, value);
    } else if(tree->left != NULL && tree->right != NULL) {
        // 左右结点都存在
        // 用右子树最小结点代替该点，并且递归删除该最小值点
        temp_node = find_min(tree->right);
        tree->value = temp_node->value;
        tree->right = delete_node(tree->right, tree->value);
    } else {
        temp_node = tree;
        // 要删除的结点只有右孩子
        if(tree->left == NULL) {
            tree = tree->right;
        } else if(tree->right == NULL) {
            // 要删除的结点只有左孩子
            tree = tree->left;
        }
        free(temp_node);
        temp_node = NULL;
    }
    return tree;
}

// 前序遍历
void pre_order(tree_node *tree) {
    if(tree == NULL) {
        return;
    }
    printf("%d ", tree->value);
    pre_order(tree->left);
    pre_order(tree->right);
}

// 中序遍历
void in_order(tree_node *tree) {
    if(tree == NULL) {
        return;
    }
    in_order(tree->left);
    printf("%d ", tree->value);
    in_order(tree->right);
}

// 后序遍历
void post_order(tree_node *tree) {
    if(tree == NULL) {
        return;
    }
    post_order(tree->left);
    post_order(tree->right);
    printf("%d ", tree->value);
}




#endif //DATA_STRUCTURE_BINARY_SEARCH_TREE_H
