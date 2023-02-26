#include "menuCommands.h"
#include "boilers.h"
//#include <stdlib.h>
void task1NewElement(Boiler** boilers, int* number){
    resizeStruct(boilers, number);
    addNewBoiler(boilers, number);
}
void task2RemoveElement(Boiler** boilers, int* number){
    if(*number>0){
        printBoilers(boilers, number);
        printf("--------------------------------------------------------------\n");
        printf("\033[0;34mType the number of element you want to delete: \033[0m");
        int choice = methodOfInputChoice(*number);
        removingElement(boilers, number, choice-1);
    }else{
        printf("There's nothing to remove.\n");
    }
}
void task3SortByTwo(Boiler** boilers, int* number){
    int choice1, choice2;
    printf("\nEnter the field(1-6):\n"
           "1. Name;\n"
           "2. Number of loops;\n"
           "3. Heating area;\n"
           "4. Thermal power;\n"
           "5. Depth;\n"
           "6. Type of solid fuel.\n"
           "Decision1: ");
    choice1 = methodOfInputInt();
    printf("\nDecision2: ");
    choice2 = methodOfInputInt();
    shellSort(*boilers, *number, choice1, choice2);
    printBoilers(boilers, number);
}
void task4Print(Boiler** boilers, int* number){
    printBoilers(boilers, number);
}
void task5ShowTheNumberOfElements(Boiler** boilers, int* number){
    showTheNumberOfElements(*number);
}
void task6Initialization(Boiler** boilers, int* number){
    printf("How many elements would you like to add?: ");
    *number = methodOfInputInt();
    creatingTheArray(boilers, *number);
    addNewNumberOfBoilers(boilers, *number);
}
