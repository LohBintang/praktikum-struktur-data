#ifndef QUEUE_H
#define QUEUE_H

struct Queue {
    int data[5];
    int head;
    int tail;
    int count;  
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, int x);
void dequeue(Queue &Q);
void printQueue(Queue Q);

#endif
