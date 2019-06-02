//
//  Tree.c
//  TreeDemo
//
//  Created by ggl on 2019/6/2.
//  Copyright © 2019 ggl. All rights reserved.
//

#include "Tree.h"

// 初始化一颗空树
void InitTree(Tree **tree) {
    *tree = (Tree *)malloc(sizeof(Tree));
    (*tree)->size = 0;
}

// 创建一颗以T以根节点，以T1，T2...,Tk为第1,2,...,k颗子树的树
Tree *CreateTree(int num, ...) {
    int i;
    va_list vl;
    Tree *tree = NULL;
    InitTree(&tree);
    
    va_start(vl, num);
    for (i = 0; i < num; i++) {
        if (i == 0) {
            tree->head[i].parent = -1;
        } else {
            tree->head[i].parent = 0;
        }
        tree->head[i].data = va_arg(vl, char);
        tree->size += 1;
    }
    va_end(vl);
    
    return tree;
}

// 返回树的根节点地址
TreeNode *Root(Tree *tree) {
    if (tree == NULL || tree->size == 0) {
        return NULL;
    }
    return tree->head;
}

// 返回node结点的双亲结点
TreeNode *Parent(Tree *tree, char node) {
    int i;
    TreeNode *rootNode = Root(tree);
    if (rootNode == NULL || rootNode->data == node) {
        return NULL;
    }
    
    for (i = 0; i < tree->size; i++) {
        TreeNode *treeNode = tree->head + i;
        if (treeNode->data == node) {
            return tree->head + treeNode->parent;
        }
    }
    
    return NULL;
}

// 返回树中结点node的值
TreeNode *Value(Tree *tree, char node) {
    int i;
    TreeNode *rootNode = Root(tree);
    if (rootNode == NULL) {
        return NULL;
    }
    
    for (i = 0; i < tree->size; i++) {
        TreeNode *treeNode = tree->head + i;
        if (treeNode->data == node) {
            return treeNode;
        }
    }
    
    return NULL;
}

// 返回树中结点node的最左孩子结点
TreeNode *LeftChild(Tree *tree, char node) {
    int i;
    int nodeIndex = -1;
    TreeNode *treeNode = NULL;
    TreeNode *n = NULL;
    TreeNode *rootNode = Root(tree);
    if (rootNode == NULL) {
        return NULL;
    }
    
    // 找到父结点
    for (i = 0; i < tree->size; i++) {
        n = tree->head + i;
        if (treeNode == NULL) {
            if (n->data == node) {
                treeNode = n;
                nodeIndex = i;
            }
            continue;
        }
        
        // 判断子结点的parent等于父结点的下标
        if (n->parent == nodeIndex) {
            return n;
        }
    }
    return NULL;
}

// 返回树中结点node的右兄弟结点
TreeNode *RightSibling(Tree *tree, char node) {
    int i;
    int parentIndex = -100;
    TreeNode *rootNode = Root(tree);
    if (rootNode == NULL) {
        return NULL;
    }
    
    // 先找到父结点的下标
    for (i = 0; i < tree->size; i++) {
        TreeNode *n = tree->head + i;
        if (parentIndex == -100) {
            if (n->data == node) {
                parentIndex = n->parent;
            }
            continue;
        }
        
        // 如果结点的parent等于父结点的下标
        if (n->parent == parentIndex) {
            return n;
        }
    }
    return NULL;
}

// 判断树空
int TreeEmpty(Tree *tree) {
    TreeNode *rootNode = Root(tree);
    if (rootNode == NULL) {
        return 1;
    }
    return 0;
}

// 打印Tree
void Print(Tree *tree) {
    int i;
    if (tree == NULL || tree->size == 0) {
        return;
    }
    
    printf("树数组信息：");
    for (i = 0; i < tree->size; i++) {
        if (i != tree->size - 1) {
            printf("[%c p:%d] -> ", tree->head[i].data, tree->head[i].parent);
        } else {
            printf("[%c p:%d]\n", tree->head[i].data, tree->head[i].parent);
        }
    }
}
