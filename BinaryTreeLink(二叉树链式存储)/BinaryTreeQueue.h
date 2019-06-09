//
//  BinaryTreeQueue.h
//  BinaryTreeLink
//
//  Created by ggl on 2019/6/9.
//  Copyright © 2019 ggl. All rights reserved.
//  队列，遵循先进先出的规则

#ifndef BinaryTreeQueue_h
#define BinaryTreeQueue_h

#define MaxQueueSize 100

#include <stdio.h>

typedef struct BinaryTreeQueue {
    void *array[MaxQueueSize];  // 底层数组
    int size;                   // 存放的元素个数
} BinaryTreeQueue;

// 初始化队列
void Queue_Init(BinaryTreeQueue *queue);

// 存放元素
void Queue_Push(BinaryTreeQueue *queue, void *element);

// 取出元素
void *Queue_Pop(BinaryTreeQueue *queue);

// 队列是否为空，为空返回1 不为空返回0
int Queue_Empty(BinaryTreeQueue *queue);

#endif /* BinaryTreeQueue_h */
