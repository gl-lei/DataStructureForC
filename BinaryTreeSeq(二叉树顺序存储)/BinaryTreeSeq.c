//
//  BinaryTree.c
//  TreeDemo
//
//  Created by ggl on 2019/6/4.
//  Copyright © 2019 ggl. All rights reserved.
//  二叉树的顺序存储结构

#include "BinaryTreeSeq.h"

// 创建以bt为根结点，lbt为左子树，rbt为右子树的二叉树
BTSEQ *Create_BT(DATATYPE2 bt, DATATYPE2 lbt, DATATYPE2 rbt) {
    // 初始化数据
    BTSEQ *btSeq = (BTSEQ *)malloc(sizeof(BTSEQ));
    btSeq->btnum = 0;
    
    // 更新二叉树
    btSeq->bt[0] = bt;
    btSeq->bt[1] = lbt;
    btSeq->bt[2] = rbt;
    btSeq->btnum = 3;
    
    return btSeq;
}

// 创建二叉树，例如 abcd#e#f，#表示无结点
BTSEQ *Create_BT1() {
    int i;
    char str[MAXSIZE];
    gets(str);
    
    // 创建二叉树结构
    BTSEQ *btSeq = (BTSEQ *)malloc(sizeof(BTSEQ));
    btSeq->btnum = 0;
    for (i = 0; i < strlen(str); i++) {
        btSeq->btnum += 1;
        btSeq->bt[i] = str[i];
    }
    
    return btSeq;
}

// 返回根结点的地址
DATATYPE2 *Root(BTSEQ *bt) {
    if (TreeEmpty(bt) || bt->bt[0] == '#') {
        return NULL;
    }
    return bt->bt;
}

// 返回结点node的地址
DATATYPE2 *Value(BTSEQ *bt, DATATYPE2 node) {
    int i;
    DATATYPE2 value;
    if (TreeEmpty(bt)) {
        return NULL;
    }
    
    // 遍历所有元素查找
    for (i = 0; i < bt->btnum; i++) {
        value = bt->bt[i];
        if (value != '#' && value == node) {
            return bt->bt + i;
        }
    }
    
    return NULL;
}

// 返回结点node的双亲结点地址
DATATYPE2 *Parent(BTSEQ *bt, DATATYPE2 node) {
    int index = -1;
    int i;
    if (TreeEmpty(bt) || node == '#') {
        return NULL;
    }
    
    for (i = 0; i < bt->btnum; i++) {
        if (bt->bt[i] == node) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return NULL;
    }
    
    return bt->bt + (index - 1) / 2;
}

// 返回结点node的左孩子地址
DATATYPE2 *LChild(BTSEQ *bt, DATATYPE2 node) {
    int i;
    int index = -1;
    if (TreeEmpty(bt) || node == '#') {
        return NULL;
    }
    
    // 查找当前node所在的位置
    for (i = 0; i < bt->btnum; i++) {
        if (bt->bt[i] == node) {
            index = i;
            break;
        }
    }
    
    if (index != -1 && (index * 2 + 1) < bt->btnum && bt->bt[index * 2 + 1] != '#') {
        return bt->bt + (index * 2 + 1);
    }
    
    return NULL;
}

// 返回结点node的右孩子地址
DATATYPE2 *RChild(BTSEQ *bt, DATATYPE2 node) {
    int i;
    int index = -1;
    if (TreeEmpty(bt) || node == '#') {
        return NULL;
    }
    
    // 查找当前node所在的位置
    for (i = 0; i < bt->btnum; i++) {
        if (bt->bt[i] == node) {
            index = i;
            break;
        }
    }
    
    if (index != -1 && (index * 2 + 2) < bt->btnum && bt->bt[index * 2 + 2] != '#') {
        return bt->bt + (index * 2 + 2);
    }
    
    return NULL;
}

// 返回二叉树的高度
int TreeDepth(BTSEQ *bt) {
    if (TreeEmpty(bt)) {
        return 0;
    }
    return ceil(log2(bt->btnum + 1));
}

// 判断二叉树是否为空，若为空，返回1 否则返回0
int TreeEmpty(BTSEQ *bt) {
    if (bt == NULL || bt->btnum == 0) {
        return 1;
    }
    return 0;
}

// 打印二叉树
void TreePrint(BTSEQ *bt) {
    int i;
    if (bt == NULL || bt->btnum == 0) {
        return;
    }
    
    printf("二叉树树数组信息：");
    for (i = 0; i < bt->btnum; i++) {
        if (i != bt->btnum - 1) {
            printf("%c ", bt->bt[i]);
        } else {
            printf("%c\n", bt->bt[i]);
        }
    }
}

// 释放二叉树占用的堆空间
void TreeDealloc(BTSEQ *bt) {
    if (bt != NULL) {
        free(bt);
    }
}
