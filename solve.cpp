#include "solve.h"

void makeLinesIndexesArray(PoemLine *poem, char *mem, size_t fileRealSize) {
    size_t currentLineIndex = 0;
    size_t currentLineSize = 0;
    for (size_t p = 0; p < fileRealSize; ++p) {
        if (mem[p] == '\n' && currentLineSize != 0) {
            poem[currentLineIndex].pointer = &mem[p - currentLineSize];
            poem[currentLineIndex].size = currentLineSize;
            currentLineSize = 0;
            ++currentLineIndex;
        } else {
            ++currentLineSize;
        }
    }
}

char makeLower(char c) {
    if (65 <= c && c <= 90) {
        c += 32;
    }
    return c;
}

int cmpByTop(const void *line1, const void *line2) {
    PoemLine fLine = *(PoemLine *) (line1);
    PoemLine sLine = *(PoemLine *) (line2);

    size_t p = 0;
    while (p < fLine.size && p < sLine.size) {
        char c1 = makeLower(fLine.pointer[p]);
        char c2 = makeLower(sLine.pointer[p]);
        if (c1 < c2) {
            return -1;
        } else if (c1 > c2) {
            return 1;
        }
        ++p;
    }

    if (fLine.size < sLine.size) {
        return -1;
    } else if (fLine.size > sLine.size) {
        return 1;
    }
    return 0;
}

int cmpByEnd(const void *line1, const void *line2) {
    PoemLine fLine = *(PoemLine *) (line1);
    PoemLine sLine = *(PoemLine *) (line2);

    size_t p = 0;
    while (p < fLine.size && p < sLine.size) {
        char c1 = makeLower(fLine.pointer[fLine.size - p]);
        char c2 = makeLower(sLine.pointer[sLine.size - p]);
        if (c1 < c2) {
            return -1;
        } else if (c1 > c2) {
            return 1;
        }
        ++p;
    }

    if (fLine.size < sLine.size) {
        return -1;
    } else if (fLine.size > sLine.size) {
        return 1;
    }
    return 0;
}

void sortByTop(PoemLine *poem, size_t linesNumber) {
    qsort(poem, linesNumber, sizeof(PoemLine), cmpByTop);
}

void sortByEnd(PoemLine *poem, size_t linesNumber) {
    qsort(poem, linesNumber, sizeof(PoemLine), cmpByEnd);
}
