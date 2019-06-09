//
//  BinaryTreeQueue.c
//  BinaryTreeLink
//
//  Created by ggl on 2019/6/9.
//  Copyright © 2019 ggl. All rights reserved.
//  队列，遵循先进先出的规则

#include "BinaryTreeQueue.h"

// 初始化队列
void Queue_Init(BinaryTreeQueue *queue) {
    queue->size = 0;
}

// 存放元素
void Queue_Push(BinaryTreeQueue *queue, void *element) {
    queue->array[queue->size] = element;
    queue->size += 1;
}

// 取出元素
void *Queue_Pop(BinaryTreeQueue *queue) {
    void *element = NULL;
    int i;
    if (Queue_Empty(queue)) {
        return NULL;
    }
    
    // 搬移元素
    element = queue->array[0];
    queue->size -= 1;
    for (i = 0; i < queue->size; i++) {
        queue->array[i] = queue->array[i+1];
    }
    
    return element;
}

// 队列是否为空，为空返回1 不为空返回0
int Queue_Empty(BinaryTreeQueue *queue) {
    if (queue->size == 0) {
        return 1;
    }
    return 0;
}
