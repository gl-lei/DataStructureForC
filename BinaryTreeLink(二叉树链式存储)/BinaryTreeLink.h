//
//  BinaryTreeLink.h
//  BinaryTreeLink
//
//  Created by ggl on 2019/6/5.
//  Copyright © 2019 ggl. All rights reserved.
//  二叉树的链式存储结构

#ifndef BinaryTreeLink_h
#define BinaryTreeLink_h

#include <stdio.h>
#include <stdlib.h>

typedef struct BTLink {
    char data;              // 结点值
    struct BTLink *lChild;  // 左孩子指针
    struct BTLink *rChild;  // 右孩子指针
} BTLink;

// 创建二叉树，例如 AB#D##CEG###FH##I##，#表示空结点
BTLink *Create_BT();

// 返回根结点的地址
BTLink *Root(BTLink *bt);

// 返回结点node的地址
BTLink *Value(BTLink *bt, char node);

// 返回结点node的双亲结点地址
BTLink *Parent(BTLink *bt, char node);

// 返回结点node的左孩子地址
BTLink *LChild(BTLink *bt, char node);

// 返回结点node的右孩子地址
BTLink *RChild(BTLink *bt, char node);

// 判断二叉树是否为空，若为空，返回1 否则返回0
int TreeEmpty(BTLink *bt);

// 打印二叉树
void TreePrint(BTLink *bt);

// 释放二叉树占用的堆空间
void TreeDealloc(BTLink *bt);

// 先序遍历
void PreOrder(BTLink *bt);

// 中序遍历
void InOrder(BTLink *bt);

// 后序遍历
void PostOrder(BTLink *bt);

#endif /* BinaryTreeLink_h */
