//
//  BinaryTreeLink.c
//  BinaryTreeLink
//
//  Created by ggl on 2019/6/5.
//  Copyright © 2019 ggl. All rights reserved.
//  二叉树的链式存储结构

#include "BinaryTreeLink.h"
#include "BinaryTreeQueue.h"
#include <string.h>
#include <math.h>

// 创建二叉树，例如 AB#D##CEG###FH##I##，#表示空结点
void Create_BT_Node(BTLink **bt, char values[], int *index, int const size) {
    if (*index >= size) {
        return;
    }
    
    if (values[*index] == '#') {
        *bt = NULL;
        (*index)++;
    } else {
        (*bt) = (BTLink *)malloc(sizeof(BTLink));
        (*bt)->data = values[(*index)++];
        Create_BT_Node(&(*bt)->lChild, values, index, size);
        Create_BT_Node(&(*bt)->rChild, values, index, size);
    }
}

// 创建二叉树
BTLink *Create_BT() {
    BTLink *bt;
    char values[100];
    int index = 0;
    int size = 0;
    printf("请输入二叉树结点，例如AB#D##CEG###FH##I##，#表示空结点:");
    gets(values);
    size = (int)strlen(values);
    
    if (size > 0) {
        Create_BT_Node(&bt, values, &index, size);
    }
    
    return bt;
}

// 返回根结点的地址
BTLink *Root(BTLink *bt) {
    return bt;
}

// 返回结点node的地址
BTLink *Value(BTLink *bt, char node) {
    BTLink *lLink = NULL;
    BTLink *rLink = NULL;
    
    if (bt == NULL) {
        return NULL;
    }
    
    if (bt->data == node) {
        return bt;
    }
    
    lLink = Value(bt->lChild, node);
    if (lLink != NULL) {
        return lLink;
    }
    
    rLink = Value(bt->rChild, node);
    if (rLink != NULL) {
        return rLink;
    }
    
    return NULL;
}

// 返回结点node的双亲结点地址
BTLink *Parent(BTLink *bt, char node) {
    BTLink *lLink = NULL;
    BTLink *rLink = NULL;
    
    if (bt == NULL || bt->data == node) {
        return NULL;
    }
    
    if (bt->lChild != NULL && bt->lChild->data == node) {
        return bt;
    }
    
    if (bt->rChild != NULL && bt->rChild->data == node) {
        return bt;
    }
    
    lLink = Parent(bt->lChild, node);
    if (lLink != NULL) {
        return lLink;
    }
    
    rLink = Parent(bt->rChild, node);
    if (rLink != NULL) {
        return rLink;
    }
    
    return NULL;
}

// 返回结点node的左孩子地址
BTLink *LChild(BTLink *bt, char node) {
    BTLink *link = Value(bt, node);
    if (link == NULL) {
        return NULL;
    }
    
    return link->lChild;
}

// 返回结点node的右孩子地址
BTLink *RChild(BTLink *bt, char node) {
    BTLink *link = Value(bt, node);
    if (link == NULL) {
        return NULL;
    }
    
    return link->rChild;
}

// 判断二叉树是否为空，若为空，返回1 否则返回0
int TreeEmpty(BTLink *bt) {
    if (bt == NULL) {
        return 1;
    }
    
    return 0;
}

// 打印二叉树
void TreePrint(BTLink *bt) {
    BinaryTreeQueue queue;
    BTLink *link;
    if (bt == NULL) {
        return;
    }
    
    printf("按照层级遍历:");
    Queue_Init(&queue);
    Queue_Push(&queue, bt);
    while (!Queue_Empty(&queue)) {
        link = (BTLink *)Queue_Pop(&queue);
        printf("%c ", link->data);
        if (link->lChild != NULL) {
            Queue_Push(&queue, link->lChild);
        }
        
        if (link->rChild != NULL) {
            Queue_Push(&queue, link->rChild);
        }
    }
    printf("\n");
}

// 释放二叉树占用的堆空间
void TreeDealloc(BTLink *bt) {
    if (bt == NULL) {
        TreeDealloc(bt->lChild);
        TreeDealloc(bt->rChild);
        free(bt);
    }
}

// 先序遍历
void PreOrder(BTLink *bt) {
    if (bt != NULL) {
        printf("%c ", bt->data);
        PreOrder(bt->lChild);
        PreOrder(bt->rChild);
    }
}

// 中序遍历
void InOrder(BTLink *bt) {
    if (bt != NULL) {
        InOrder(bt->lChild);
        printf("%c ", bt->data);
        InOrder(bt->rChild);
    }
}

// 后序遍历
void PostOrder(BTLink *bt) {
    if (bt != NULL) {
        PostOrder(bt->lChild);
        PostOrder(bt->rChild);
        printf("%c ", bt->data);
    }
}
