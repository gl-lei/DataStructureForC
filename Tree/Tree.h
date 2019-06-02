//
//  Tree.h
//  TreeDemo
//
//  Created by ggl on 2019/6/2.
//  Copyright © 2019 ggl. All rights reserved.
//  树的双亲表示法实现

#ifndef Tree_h
#define Tree_h

#define MaxCapcity 100

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// 树结点
typedef struct
{
    char data;          // 结点数据
    int parent;         // 双亲结点所在位置下标
} TreeNode;

// 树
typedef struct
{
    int size;                   // 结点的个数
    TreeNode head[MaxCapcity];  // 数的结点
} Tree;

// 初始化一颗空树
void InitTree(Tree **tree);

// 创建一颗以T以根节点，以T1，T2...,Tk为第1,2,...,k颗子树的树
Tree *CreateTree(int num, ...);

// 返回树的根节点地址
TreeNode *Root(Tree *tree);

// 返回node结点的双亲结点
TreeNode *Parent(Tree *tree, char node);

// 返回树中结点node的值
TreeNode *Value(Tree *tree, char node);

// 返回树中结点node的最左孩子结点
TreeNode *LeftChild(Tree *tree, char node);

// 返回树中结点node的右兄弟结点
TreeNode *RightSibling(Tree *tree, char node);

// 判断树空
int TreeEmpty(Tree *tree);

// 打印Tree
void Print(Tree *tree);


#endif /* Tree_h */
