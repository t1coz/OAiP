#ifndef INC_1LABA_MENUCOMMANDS_H
#define INC_1LABA_MENUCOMMANDS_H
#include "boilers.h"
void menuInterface(Boiler** boilers, int* number);
int methodOfInput(int size);
double methodOfInputDouble();
int methodOfInputInt();
float methodOfInputFloat();
int methodOfInputChoice(int size);
void getStr(char **string);

//tasks
void task1NewElement(Boiler** boilers, int* number);
void task2RemoveElement(Boiler** boilers, int* number);
void task3SortByTwo(Boiler** boilers, int* number);
void task4Print(Boiler** boilers, int* number);
void task5ShowTheNumberOfElements(Boiler** boilers, int* number);
void task6Initialization(Boiler** boilers, int* number);
#endif //INC_1LABA_MENUCOMMANDS_H