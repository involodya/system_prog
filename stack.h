#include <stdio.h>
#include <assert.h>
#include <string.h>

struct Stack {
    int *data;
    int capacity;
    size_t size;
};

int StackCtor(Stack *stack, int capacity);

int StackDtor(Stack *stack);

int StackResize(Stack *stack, int capacity);

int StackPush(Stack *stack, int value);

int StackPop(Stack *stack, int *x);
