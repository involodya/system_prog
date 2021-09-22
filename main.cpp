//-------------------------------------------------
//! Onegin program
//!     @version Vers 1.1
//!     @date 23. 09. 2021
//!     @brief Solving task #2 for the course "Professional Programming"
//-------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "defines.h"
#include "solve.h"


int main() {

    printf("# Onegin\n"
           "# @involodya, 2021\n\n");

    size_t size_f = 0, size_spec = 0; // размер файла в байтах, размер файла в байтах без \r
    FILE *fp = fopen("../onegin.txt", "r");

    fseek(fp, 0, SEEK_END);
    size_f = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *mem = (char *) calloc(size_f, sizeof(char));
    assert(mem);

    size_spec = fread(mem, sizeof(char), size_f, fp);

    int k = 0;
    for (int i = 0; i < size_spec; ++i) {
        printf("%d ", (int) mem[i]);
        if (mem[i] == '\n') {
            ++k;
        }
    }
    printf("\n%d\n", k);

    PoemLine* poem = (PoemLine *) calloc(k, sizeof(PoemLine));

    int c = 0;
    poem[0].pointer = &mem[0];
    for (int i = 0; i < size_spec; ++i) {
        if (mem[i] == '\n') {
            poem[c].size = &mem[i] - poem[c].pointer;
            if (size_spec - i > 1) {
                poem[++c].pointer = &mem[i + 1];
                printf("228 %d\n", i);
            }
        }
    }

    printf("\n");
    for (int i = 0; i < k; ++i) {
        printf("%p %zu\n", poem[i].pointer, poem[i].size);
    }

    return 0;
}
