#include <stdio.h>

#ifndef INC_1LABA_BOILERS_H
#define INC_1LABA_BOILERS_H

typedef enum{
    singleLoop = 1,
    doubleLoop = 2
}NumberOfLoops;

typedef struct {
    char* name;
    NumberOfLoops numberOfLoops;
    int heatingArea;
    double thermalPower;
    float depth;
    char* typeOfSolidFuel;
}Boiler;

void creatingTheArray(Boiler **boilers, int num);

void addNewBoiler(Boiler** boilers, const int* num);
void addNewNumberOfBoilers(Boiler** boilers, int num);
void removingElement(Boiler** boilers, int* num, int position);

void showTheNumberOfElements(int num);
int compare(const void *a, const void *b);

void printBoilers(Boiler** boilers, const int* num);

void resizeStruct(Boiler **boilers, int* num);
void freeStructAndArray(Boiler **boilers, int num);

#endif //INC_1LABA_BOILERS_H
