#ifndef STACK_H
#define STACK_H

const int maxEl = 20;

typedef int infotype;

struct Stack {
    infotype info[maxEl];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);

#endif
