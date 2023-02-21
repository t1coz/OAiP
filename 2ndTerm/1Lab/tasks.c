#include "menuCommands.h"
#include "boilers.h"
#include <stdlib.h>
void task1NewElement(Boiler* boilers, int* number){
    addNewBoiler(&boilers, number);
}
void task2RemoveElement(Boiler* boilers, int* number){
    if(*number>0){
        printBoilers(boilers, number);
        printf("Type the number of element you want to delete: ");
        int choice = methodOfInputChoice(*number);
        removingElement(&boilers, number, choice-1);
    }else{
        printf("There's nothing to remove.\n");
    }
}
void task3SortByTwo(Boiler* boilers, int* number){
    //qsort(boilers, number, sizeof *boilers, compare);
}
void task4Print(Boiler* boilers, int* number){
    printBoilers(boilers, number);
}
void task5Parsing(Boiler* boilers, int* number){

}
void task6ShowTheNumberOfElements(Boiler* boilers, int* number){
    showTheNumberOfElements(*number);
}