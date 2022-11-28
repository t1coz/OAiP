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
void theMostFrequent(char* str);
void deletingWords(char** str, char c);
void output (char *str);
void task1();
void task2();
#endif //INC_1_FUNCTIONS_H
