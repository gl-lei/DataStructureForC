//
//  BinaryTree.h
//  TreeDemo
//
//  Created by ggl on 2019/6/4.
//  Copyright © 2019 ggl. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#define DATATYPE2 char
#define MAXSIZE 100

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    DATATYPE2 bt[MAXSIZE];      // 100个元素的数组
    int btnum;                  // 结点个数
}BTSEQ;

// 创建以bt为根结点，lbt为左子树，rbt为右子树的二叉树
BTSEQ *Create_BT(DATATYPE2 bt, DATATYPE2 lbt, DATATYPE2 rbt);

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


#endif /* BinaryTree_h */
