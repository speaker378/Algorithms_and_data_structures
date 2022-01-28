//
//  Queue.h
//  Algorithms_and_data_structures
//
//  Created by Сергей Черных on 16.01.2022.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    struct Node* front;
    struct Node* rear;
} Queue;

Node* createNode(int value);
Queue* createQueue(void);
void enQueue(Queue* queue, int value);
int deQueue(Queue* queue);
int queueIsEmpty(Queue* queue);

#endif /* Queue_h */
