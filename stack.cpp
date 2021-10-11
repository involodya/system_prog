#include "stack.h"

//TODO написать обработчик яда
int StackCtor(Stack *stack, size_t capacity) {
    assert(stack);

    stack->data = (int *) calloc(capacity, sizeof(int));
    memset(stack->data, 1, capacity * sizeof(int));

    stack->capacity = capacity;
    // ...
    stack->size = 0;
    // ...

    return 0;
}

int StackDtor(Stack *stack) {
    assert(stack);
    assert(stack->size != -1);

    memset(stack->data, PURIFIED_MEMORY_POISON, stack->capacity * sizeof(int));
    free(stack->data);

    stack->data = (int *) 13;
    stack->capacity = 0;
    stack->size = -1;

    return 0;
}

int StackResize(Stack *stack, size_t capacity) {
    assert(stack);
    assert(stack->size <= capacity);

    int *data = (int *) calloc(capacity, sizeof(int));
    memset(data, POISON_OF_NOT_ADDED_ELEMENT, capacity * sizeof(int));
    memcpy(data, stack->data, stack->size * sizeof(int));

    memset(stack->data, PURIFIED_MEMORY_POISON, stack->capacity * sizeof(int));
    free(stack->data);

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

    stack->data[stack->size] = value;
    stack->size++;

    return 0;
}

int StackPop(Stack *stack, int *x) {
    assert(stack);
    assert(stack->size != -1);

    *x = stack->data[--stack->size];
    stack->data[stack->size + 1] = POISON_OF_NOT_ADDED_ELEMENT;

    if (stack->capacity / 4 - stack->size <= 1 && stack->capacity > 10) {
        StackResize(stack, stack->capacity / 2);
    }

    return 0;
}
