#include "dump.h"

int dump(const char *filename, const char *func, size_t line, const char *s, const Stack *st) {
    fprintf(stderr, "Stack<int>[%p] \"%s\" at %s() at %s (%zu)\n", st, s, func, filename, line);
    fprintf(stderr, "\t{\n");
    fprintf(stderr, "\tsize\t\t= %zu\n", st->size);
    fprintf(stderr, "\tcapacity\t= %zu\n", st->capacity);
    fprintf(stderr, "\tdata[%p]\n", st->data);
    fprintf(stderr, "\t\t{\n");
    for (size_t i = 0; i < st->capacity; ++i) {
        if (i < st->size) {
            fprintf(stderr, "\t\t*");
        } else {
            fprintf(stderr, "\t\t ");
        }
        fprintf(stderr, "[%zu] = %d\n", i, st->data[i]);
        //if (*(char*) &st->data[i] == (char) PURIFIED_MEMORY_POISON) {
            fprintf(stderr, " (POISON)%d %d\n", *(char*) &st->data[i], PURIFIED_MEMORY_POISON);
        //}
    }
    fprintf(stderr, "\t\t}\n");
    fprintf(stderr, "\t}\n");
    return 0;
}
