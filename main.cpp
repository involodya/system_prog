//-------------------------------------------------
//! Stack realization
//!     @version Vers 1.0
//!     @date 22. 09. 2021
//!     @brief Solving task #3 for the course "Professional Programming"
//------------------------------------------------

#include "defines.h"
#include "stack.h"


int main() {
    Stack st = {};
    StackCtor(&st, 3);
    StackPush(&st, 10);
    StackPush(&st, 20);
    StackPush(&st, 30);
    int x;
    StackPop(&st, &x);
    printf("Ans.: %d\n", x);
    StackPop(&st, &x);
    printf("Ans.: %d\n", x);
    StackPop(&st, &x);
    printf("Ans.: %d\n", x);
    printf("Capacity: %d\n", st.capacity);
    StackDtor(&st);
}
