#include "stack.h"

int StackCtor(Stack *stack, int capacity) {
    assert(stack);

    stack->data = (int *) calloc(capacity, sizeof(int));
    stack->capacity = capacity;
    // ...
    stack->size = 0;
    // ...

    return 0;
}

int StackDtor(Stack *stack) {
    assert(stack);
    assert(stack->size != -1);

    memset(stack->data, 0xFD, stack->capacity * sizeof(int));
    free(stack->data);
    stack->data = (int *) 13;
    stack->capacity = 0;
    stack->size = -1;

    return 0;
}

int StackResize(Stack *stack, int capacity) {
    assert(stack);
    assert(stack->size <= capacity);

    int *data = (int *) calloc(capacity, sizeof(int));
    memcpy(data, stack->data, stack->size * sizeof(int));

    stack->data = data;
    stack->capacity = capacity;

    return 0;
}

int StackPush(Stack *stack, int value) {
    assert(stack);
    assert(stack->size != -1);

    while (stack->capacity - stack->size <= 1) {
        StackResize(stack, 2 * stack->capacity);
    }

    //printf("Push\t%p\n", stack->data);
    stack->data[stack->size] = value;
    //printf("Push\t%d\n", stack->data[stack->size]);
    stack->size++;

    return 0;
}

int StackPop(Stack *stack, int *x) {
    assert(stack);
    assert(stack->size != -1);

    //printf("Pop\t%p\n", stack->data);
    //printf("Pop\t%d\n", stack->data[--stack->size]);
    *x = stack->data[--stack->size];
    //printf("Pop\t%d\n", *x);

    if (stack->capacity / 4 - stack->size <= 1 && stack->capacity > 10) {
        StackResize(stack, stack->capacity / 2);
    }

    return 0;
}