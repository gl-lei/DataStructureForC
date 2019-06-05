//
//  main.c
//  BinaryTreeSeq
//
//  Created by ggl on 2019/6/5.
//  Copyright © 2019 ggl. All rights reserved.
//  二叉树的顺序存储结构测试

#include <stdio.h>
#include "BinaryTreeSeq.h"

int main(int argc, const char * argv[]) {
    char *parent = NULL;
    char *lChild = NULL;
    char *rChild = NULL;
    
    printf("\n==============二叉树结构===============\n");
    //创建二叉树 abcdefg##hi#j##
    BTSEQ *bt = Create_BT1();
    TreePrint(bt);
    
    parent = Parent(bt, 'c');
    lChild = LChild(bt, 'e');
    rChild = RChild(bt, 'e');
    printf("c的父结点: %c\n", parent == NULL ? ' ' : *parent);
    printf("e的左孩子结点: %c\n", lChild == NULL ? ' ' : *lChild);
    printf("e的右孩子结点: %c\n", rChild == NULL ? ' ' : *rChild);
    
    TreeDealloc(bt);
    return 0;
}
