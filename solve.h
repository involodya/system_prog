#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//!
//! Structure of poem line
//!
//! @param pointer pointer to the first element of the line
//! @param size size of the line
//!
struct PoemLine {
    char *pointer;
    size_t size;
};

//!
//! Make an array of address of lines
//!
//! @param [out] poem an array to write
//! @param [in] mem dynamic character array
//! @param [in] fileRealSize size of mem
//!
void makeLinesIndexesArray(PoemLine *poem, char *mem, size_t fileRealSize);

//!
//! Make symbol c lower ( A -> a )
//!
//! @param [out] c some symbol
//!
void makeLower(char *c);

//!
//! Sorting poem array by lines start
//!
//! @param [out] poem poem array
//! @param [in] linesNumber size of poem array
//!
void sortByTop(PoemLine *poem, size_t linesNumber);

//!
//! Sorting poem array by lines start
//!
//! @param [out] poem poem array
//! @param [in] linesNumber size of poem array
//!
void sortByEnd(PoemLine *poem, size_t linesNumber);

//!
//! Comparator to sorting poem array by lines start
//!
int cmpByTop(const void *line1, const void *line2);

//!
//! Comparator to sorting poem array by lines start
//!
int cmpByEnd(const void *line1, const void *line2);
