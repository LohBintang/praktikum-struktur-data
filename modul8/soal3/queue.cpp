#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
    Q.count = 0;
}

bool isEmptyQueue(Queue Q) {
    return (Q.count == 0);
}

bool isFullQueue(Queue Q) {
    return (Q.count == 5);
}

void enqueue(Queue &Q, int x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
        return;
    }

    Q.data[Q.tail] = x;
    Q.tail = (Q.tail + 1) % 5;
    Q.count++;
}

void dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return;
    }

    Q.head = (Q.head + 1) % 5;
    Q.count--;
}

void printQueue(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    int i = Q.head;
    int printed = 0;

    while (printed < Q.count) {
        cout << Q.data[i] << " ";
        i = (i + 1) % 5;
        printed++;
    }
    cout << endl;
}
