#include "functions.c"
#ifndef INC_1_FUNCTIONS_H
#define INC_1_FUNCTIONS_H
char* getStr();
int isLetter(char s);
int strLen(char *str);
int strCmp(char *s1, char *s2);
int countWords(char *s);
char inputChecking();
int methodinputCh();
//1 task
char **memory(int n);
void splittingInAnotherArray(char* str, char*** words);
int mostRepeated(char*arr, char** words);
void outputOfTheMostFreqWord (char** words, int maxIndex);
void deletingAarr(char **arr, int n);
//2 task
void deletingWords(char** str, char c);
void output (char *str);
void task1();
void task2();
#endif //INC_1_FUNCTIONS_H
