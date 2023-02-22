#include "menuCommands.h"
#include "boilers.h"
#include <stdlib.h>
void task1NewElement(Boiler** boilers, int* number){
    resizeStruct(boilers, number);
    addNewBoiler(boilers, number);
//    addNewBoiler(boilers, number);
//    resizeStruct(boilers, number);
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
    qsort(*boilers, *number, sizeof (Boiler*), compare);
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
void task7Parsing(Boiler** boilers, int* number){

}