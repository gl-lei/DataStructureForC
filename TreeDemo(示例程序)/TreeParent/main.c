//
//  main.c
//  TreeParent
//
//  Created by ggl on 2019/6/5.
//  Copyright © 2019 ggl. All rights reserved.
//  树的双亲表示法实现测试

#include <stdio.h>
#include "TreeParent.h"

int main(int argc, const char * argv[]) {
    // 树结构
    printf("==============树结构===============\n");
    TreeNode *treeNode = NULL;
    TreeNode *rightSiblingNode = NULL;
    Tree *tree = CreateTree(5, 'R', 'A', 'B', 'C', 'D');
    TreePrint(tree);
    
    treeNode = Parent(tree, 'C');
    printf("C的父结点: %c\n", treeNode->data);
    
    rightSiblingNode = RightSibling(tree, 'A');
    printf("A的兄弟结点: %c\n", rightSiblingNode->data);
    
    TreeDealloc(tree);
    return 0;
}
