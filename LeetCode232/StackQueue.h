//
//  StackQueue.h
//  LeetCode232
//
//  Created by njim3 on 2018/12/21.
//  Copyright © 2018 njim3. All rights reserved.
//

#ifndef StackQueue_h
#define StackQueue_h

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int* data;
    
    int size;
    int top;
} Stack;

typedef struct {
    Stack* s1;
    Stack* s2;
} MyQueue;

Stack* createStack(int maxSize);
bool isStackEmpty(Stack* stack);
bool isStackFull(Stack* stack);
int peekStack(Stack* stack);
void pushStack(Stack* stack, int val);
int popStack(Stack* stack);
void destroyStack(Stack* stack);
MyQueue* myQueueCreate(int maxSize);
void myQueuePush(MyQueue* obj, int x);
int myQueuePop(MyQueue* obj);
int myQueuePeek(MyQueue* obj);
bool myQueueEmpty(MyQueue* obj);
void myQueueFree(MyQueue* obj);

#endif /* StackQueue_h */
