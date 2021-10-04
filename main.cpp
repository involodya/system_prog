//-------------------------------------------------
//! Onegin program
//!     @version Vers 2.1
//!     @date 29. 09. 2021
//!     @brief Solving task #2 for the course "Professional Programming"
//-------------------------------------------------

#include "solve.h"


int main(/* TODO: int argc, .... */) {

    printf("# Onegin\n"
           "# @involodya, 2021\n\n");
    // text construct
    FILE *fileInput = fopen("../onegin.txt", "rb");

    // TODO func
    //! размер файла в байтах
    fseek(fileInput, 0, SEEK_END);
    size_t fileSize = ftell(fileInput);
    fseek(fileInput, 0, SEEK_SET);

    //! память под текст
    // TODO func
    char *mem = (char *) calloc(fileSize + 1, sizeof(char));
    // TODO \0
    assert(mem);

    //! размер файла в байтах без \r
    //! Записываем в mem кусок из fileInput размером fileSize (т.е. весь файл)
    size_t fileRealSize = fread(mem, sizeof(char), fileSize, fileInput);
    // TODO ERROR
    // TODO \0
    // printf("read_size: %zu file_size: %zu \n", fileRealSize, fileSize);
    fclose(fileInput);

    //! вычисляем количество строк
    // func
    size_t linesNumber = 0;
    // TODO strchr
    for (size_t i = 0; i < fileRealSize; ++i) {
        if (mem[i] == '\n') {
            ++linesNumber;
        } // TODO \n\0
    }

    //! создаем массив структур строк поэмы и его копию для восстановления
    PoemLine *poem = (PoemLine *) calloc(linesNumber, sizeof(PoemLine));
    assert(poem);
    // buffer
    PoemLine *poemSaved = (PoemLine *) calloc(linesNumber, sizeof(PoemLine));
    assert(poemSaved);
    makeLinesIndexesArray(poem, mem, fileRealSize);
    // memcpy(poemSaved, poem, linesNumber * sizeof(PoemLine));

    //! сортируем строки
    sortByTop(poem, linesNumber);
    sortByEnd(poem, linesNumber);
    sortOrigin(poem, poemSaved, linesNumber);

    //! выводим строки в файл
    // TODO 2 func output
    FILE *fileOutput = fopen("../rhymed_onegin.txt", "w");
    // ERROR
    for (size_t p = 0; p < linesNumber; ++p) {
        char *currentString = poem[p].pointer;
        fwrite(currentString, sizeof(char), poem[p].size + 1, fileOutput);
        //  ERROR
    }
    fclose(fileOutput);

    //  destruct text
    free(mem);
    free(poem);

    return 0;
}
