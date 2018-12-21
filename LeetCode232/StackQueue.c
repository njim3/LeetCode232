//
//  StackQueue.c
//  LeetCode232
//
//  Created by njim3 on 2018/12/21.
//  Copyright © 2018 njim3. All rights reserved.
//

#include "StackQueue.h"
#include <malloc/malloc.h>
#include <stdlib.h>

Stack* createStack(int maxSize) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    
    stack->data = (int*)malloc(sizeof(int) * maxSize);
    stack->size = maxSize;
    stack->top = -1;
    
    return stack;
}

bool isStackEmpty(Stack* stack) {
    if (stack->top == -1)
        return true;
    
    return false;
}

bool isStackFull(Stack* stack) {
    if ((stack->size - 1) == stack->top)
        return true;
    
    return false;
}

int peekStack(Stack* stack) {
    if (isStackEmpty(stack))
        return -1;
    
    return stack->data[stack->top];
}

void pushStack(Stack* stack, int val) {
    if (isStackFull(stack))
        return ;
    
    stack->data[++stack->top] = val;
}

int popStack(Stack* stack) {
    if (isStackEmpty(stack))
        return -1;
    
    return stack->data[stack->top--];
}

void destroyStack(Stack* stack) {
    free(stack->data);
    free(stack);
}

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    
    queue->s1 = createStack(maxSize);
    queue->s2 = createStack(maxSize);
    
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    // if queue is full, return
    if (isStackFull(obj->s1))
        return ;
    
    while (!isStackEmpty(obj->s1)) {
        pushStack(obj->s2, popStack(obj->s1));
    }
    
    pushStack(obj->s2, x);
    
    while (!isStackEmpty(obj->s2)) {
        pushStack(obj->s1, popStack(obj->s2));
    }
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (isStackEmpty(obj->s1))
        return -1;
    
    return popStack(obj->s1);
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (isStackEmpty(obj->s1))
        return -1;
    
    return peekStack(obj->s1);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return isStackEmpty(obj->s1);
}

void myQueueFree(MyQueue* obj) {
    destroyStack(obj->s1);
    destroyStack(obj->s2);
    
    free(obj);
}
