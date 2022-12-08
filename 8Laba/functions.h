#include "functions.c"
#ifndef INC_1_FUNCTIONS_H
#define INC_1_FUNCTIONS_H
int isLetter(char s);
int strLen(char *string);
int countWords(char **string);
int* memory(int n);
void deletingArr(char **arr, int n);
void output(int argc, int* size, char **string);
#endif //INC_1_FUNCTIONS_H
