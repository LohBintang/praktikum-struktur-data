#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;
    cout << "--------------------" << endl;
    cout << "H - T | Queue Info" << endl;
    cout << "--------------------" << endl;

    Queue Q;
    createQueue(Q);

    enqueue(Q, 5); printQueue(Q);
    enqueue(Q, 2); printQueue(Q);
    enqueue(Q, 7); printQueue(Q);

    dequeue(Q); printQueue(Q);
    dequeue(Q); printQueue(Q);

    enqueue(Q, 4); printQueue(Q);

    dequeue(Q); printQueue(Q);
    dequeue(Q); printQueue(Q);

    return 0;
}
