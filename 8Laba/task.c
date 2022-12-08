#include "functions.h"
void task(int argc, char** argv){
    if (argc == 1) {
        printf("\nThere is only 1 argument, but should be greater than one.\n"
               "\033[0;31mFinishing the program.\033[0m\n\n");
        return;
    }
    printf("\n\033[0;32mMerge sort an array of strings in ascending order of word count.\n\n\033[0m");
    char **inputStrings = memoryChar(argc);
    int *size = memory(argc);
    fillAndCopyArrays(argc, inputStrings, argv, &size);
    mergeSort(&inputStrings, &size, 0, argc - 2);
    printf("\n\033[0;33mFinal sorted array:\033[0m\n");
    output(argc, size, inputStrings);
    deletingArr(inputStrings, argc);
    free(size);
}
