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

typedef struct BTLink {
    char data;              // 结点值
    struct BTLink *lChild;  // 左孩子指针
    struct BTLink *rChild;  // 右孩子指针
} BTLink;

#endif /* BinaryTreeLink_h */
