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
    char* typeOfSolidFuel;
    float depth;
}Boiler;

Boiler *creatingTheArray(int number);
void addNewBoiler(Boiler** boilers, int* num);
void removingElement(Boiler** boilers, int* num, int position);
void showTheNumberOfElements(int num);
void printBoilers(Boiler* boilers, int* num);
void printBoilersCharacteristics(Boiler* boilers, int i);
void freeArray(Boiler* boilers);
//int compare(const void *a, const void *b);
#endif //INC_1LABA_BOILERS_H
