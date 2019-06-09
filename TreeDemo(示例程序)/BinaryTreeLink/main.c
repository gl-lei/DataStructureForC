//
//  main.c
//  BinaryTreeLink
//
//  Created by ggl on 2019/6/5.
//  Copyright © 2019 ggl. All rights reserved.
//  二叉树的链式存储结构测试

#include <stdio.h>
#include "BinaryTreeLink.h"
#include "BinaryTreeQueue.h"

int main(int argc, const char * argv[]) {
    // 创建二叉树 AB#D##CEG###FH##I##
    // ABD##EH##I##CF#J##G##
    BTLink *pLink;
    BTLink *lChildLink;
    BTLink *rChildLink;
    BTLink *binaryTree = Create_BT();
    TreePrint(binaryTree);
    
    // 返回H结点的父结点F
    pLink = Parent(binaryTree, 'H');
    printf("H结点的父结点: %c\n", pLink->data);
    
    // 返回C结点的左孩子结点E
    lChildLink = LChild(binaryTree, 'E');
    printf("E结点的左孩子结点: %c\n", lChildLink->data);
    
    // 返回D结点的右孩子NULL
    rChildLink = RChild(binaryTree, 'D');
    if (rChildLink != NULL) {
        printf("E结点的右孩子结点: %c\n", rChildLink->data);
    } else {
        printf("E结点的右孩子结点为空\n");
    }
    
    
    // 先序遍历
    printf("二叉树先序遍历:");
    PreOrder(binaryTree);
    printf("\n");
    
    // 中序遍历
    printf("二叉树中序遍历:");
    InOrder(binaryTree);
    printf("\n");
    
    // 后序遍历
    printf("二叉树后序遍历:");
    PostOrder(binaryTree);
    printf("\n");
    
    // 释放二叉树
    TreeDealloc(binaryTree);
    
    return 0;
}
