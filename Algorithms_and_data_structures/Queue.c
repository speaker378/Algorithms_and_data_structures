//
//  Queue.c
//  Algorithms_and_data_structures
//
//  Created by Сергей Черных on 16.01.2022.
//

#include "Queue.h"
#include <stdlib.h>

Node* createNode(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

Queue* createQueue(void) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enQueue(Queue* queue, int value) {
    Node* temp = createNode(value);
    
    if (queue->rear == NULL) {
        queue->front = temp;
        queue->rear = temp;
        return;
    }
    
    queue->rear->next = temp;
    queue->rear = temp;
}

int deQueue(Queue* queue) {
    if (queue->front == NULL) {
        return -1;
    }
    
    int value;
    Node* temp = queue->front;
    value = queue->front->data;
    queue->front = queue->front->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    return value;
}

int queueIsEmpty(Queue* queue) {
    if (queue->rear) {
        return 0;
    }
    else {
        return 1;
    }
}
