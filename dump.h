#include "stack.h"

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define DUMP(varname) dump(__FILENAME__, __FUNCTION__, __LINE__, #varname, varname);

int dump(const char *filename, const char *func, size_t line, const char *s, const Stack *st);
