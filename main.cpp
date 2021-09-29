//-------------------------------------------------
//! Onegin program
//!     @version Vers 2.0
//!     @date 29. 09. 2021
//!     @brief Solving task #2 for the course "Professional Programming"
//-------------------------------------------------

#include "defines.h"
#include "solve.h"


int main() {

    printf("# Onegin\n"
           "# @involodya, 2021\n\n");

    FILE *fileInput = fopen("../onegin.txt", "r");

    //! размер файла в байтах
    size_t fileSize = 0;
    fseek(fileInput, 0, SEEK_END);
    fileSize = (size_t) ftell(fileInput);
    fseek(fileInput, 0, SEEK_SET);

    //! память под текст
    char *mem = (char *) calloc(fileSize, sizeof(char));
    assert(mem);

    //! размер файла в байтах без \r
    size_t fileRealSize = 0;
    //! Записываем в mem кусок из fileInput размером fileSize (т.е. весь файл)
    fileRealSize = fread(mem, sizeof(char), fileSize, fileInput);
    fclose(fileInput);

    //! вычисляем количество строк
    size_t linesNumber = 0;
    for (size_t i = 0; i < fileRealSize; ++i) {
        if (mem[i] == '\n') {
            ++linesNumber;
        }
    }

    //! создаем массив структур строк поэмы
    PoemLine *poem = (PoemLine *) calloc(linesNumber, sizeof(PoemLine));
    assert(poem);
    makeLinesIndexesArray(poem, mem, fileRealSize);

    //! сортируем строки
    sortByTop(poem, linesNumber);
    sortByEnd(poem, linesNumber);

    //! выводим строки в файл
    FILE *fileOutput = fopen("../rhymed_onegin.txt", "w");
    for (size_t p = 0; p < linesNumber; ++p) {
        char *currentString = poem[p].pointer;
        fwrite(currentString, sizeof(char), poem[p].size + 1, fileOutput);
    }
    fclose(fileOutput);

    free(mem);
    free(poem);

    return 0;
}
