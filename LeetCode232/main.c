//
//  main.c
//  LeetCode232
//
//  Created by njim3 on 2018/12/21.
//  Copyright © 2018 njim3. All rights reserved.
//

#include <stdio.h>
#include "StackQueue.h"

int main(int argc, const char * argv[]) {
    int maxSize = 10;
    
    MyQueue* queue = myQueueCreate(maxSize);
    
    for (int i = 10; i <= 80; i += 10) {
        myQueuePush(queue, i);
    }
    
    printf("Queue top: %i\n", myQueuePeek(queue));
    
    int popElem = myQueuePop(queue);
    
    printf("Pop Elem: %i, queue top: %i\n", popElem, myQueuePeek(queue));
    
    myQueueFree(queue);
    
    return 0;
}
