//
//  BinaryTree.h
//  TreeDemo
//
//  Created by ggl on 2019/6/4.
//  Copyright © 2019 ggl. All rights reserved.
//  二叉树的顺序存储结构

#ifndef BinaryTree_h
#define BinaryTree_h

#define DATATYPE2 char
#define MAXSIZE 100

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    DATATYPE2 bt[MAXSIZE];      // 100个元素的数组
    int btnum;                  // 结点个数
}BTSEQ;

// 创建以bt为根结点，lbt为左子树，rbt为右子树的二叉树
BTSEQ *Create_BT(DATATYPE2 bt, DATATYPE2 lbt, DATATYPE2 rbt);

// 循环创建二叉树，例如 ab##c##，#表示
BTSEQ *Create_BT1(void);

// 返回根结点的地址
DATATYPE2 *Root(BTSEQ *bt);

// 返回结点node的地址
DATATYPE2 *Value(BTSEQ *bt, DATATYPE2 node);

// 返回结点node的双亲结点地址
DATATYPE2 *Parent(BTSEQ *bt, DATATYPE2 node);

// 返回结点node的左孩子地址
DATATYPE2 *LChild(BTSEQ *bt, DATATYPE2 node);

// 返回结点node的右孩子地址
DATATYPE2 *RChild(BTSEQ *bt, DATATYPE2 node);

// 返回二叉树的高度
int TreeDepth(BTSEQ *bt);

// 判断二叉树是否为空，若为空，返回1 否则返回0
int TreeEmpty(BTSEQ *bt);

// 打印二叉树
void TreePrint(BTSEQ *bt);

// 释放二叉树占用的堆空间
void TreeDealloc(BTSEQ *bt);


#endif /* BinaryTree_h */
