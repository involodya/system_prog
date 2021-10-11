#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "defines.h"

struct Stack {
    int *data;
    size_t capacity;
    size_t size;
};

int StackCtor(Stack *stack, size_t capacity);

int StackDtor(Stack *stack);

int StackResize(Stack *stack, size_t capacity);

int StackPush(Stack *stack, int value);

int StackPop(Stack *stack, int *x);

//int StackPrint(Stack *stack, __FIL)