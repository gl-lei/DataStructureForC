//
//  main.c
//  TreeDemo
//
//  Created by ggl on 2019/6/2.
//  Copyright © 2019 ggl. All rights reserved.
//

#include <stdio.h>
#include "Tree.h"

int main(int argc, const char * argv[]) {
    TreeNode *treeNode = NULL;
    TreeNode *rightSiblingNode = NULL;
    Tree *tree = CreateTree(5, 'R', 'A', 'B', 'C', 'D');
    Print(tree);
    
    treeNode = Parent(tree, 'C');
    printf("C的父结点: %c\n", treeNode->data);
    
    rightSiblingNode = RightSibling(tree, 'A');
    printf("A的兄弟结点: %c\n", rightSiblingNode->data);
    return 0;
}
