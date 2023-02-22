#include "menuCommands.h"
#include "boilers.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void menuInterface(Boiler** boilers, int* number){
    void (*ptrMenu[])(Boiler**, int*) = {task1NewElement, task2RemoveElement,
                           task3SortByTwo, task4Print, task5ShowTheNumberOfElements,task6Initialization, task7Parsing};
    int choice;
    while(1){
        if(*number==0){
            printf("\n\033[0;31mThere is no elements in the structure yet.\033[0m\n");
        }
        printf("\n\033[0;31mChoose what to do with the structure:\033[0m"
               "\n1. Add new element."
               "\n2. Delete existing element."
               "\n3. Sort elements by TWO characteristics."
               "\n4. Print all the elements."
               "\n5. Show the number of elements."
               "\n6. Initialize the struct."
               "\n\033[0;33m(Type 99 to exit the program)\033[0m\n"
               "\n\033[0;32mDecision: \033[0m");
        choice = methodOfInput(sizeof(ptrMenu)/sizeof(ptrMenu[0]));
        if (choice == 99){
            printf("\n\033[0;31mFinishing the program.\n\033[0m");
            freeStructAndArray(boilers, *number);
            exit(0);
        }
        ptrMenu[choice-1](boilers, number);
    }
}
int methodOfInput(int size){
    float num;
    while (scanf("%f", &num) != 1 || num != (int)num || (!((int)num >=1 && (int)num <=size)&& (int)num != 99) || getchar() != '\n') {
        printf("Try better:\n");
        rewind(stdin);
    }
    return num;
}
int methodOfInputChoice(int size){
    float num;
    while (scanf("%f", &num) != 1 || num != (int)num || (!((int)num >=1 && (int)num <=size)) || getchar() != '\n') {
        printf("Try better:\n");
        rewind(stdin);
    }
    return num;
}
double methodOfInputDouble(){
    double num;
    while (scanf("%lf", &num) != 1 || num <=0 || getchar() != '\n') {
        printf("Try better:\n");
        rewind(stdin);
    }
    return num;
}
int methodOfInputInt(){
    int num;
    while (scanf("%d", &num) != 1 || num <=0 || getchar() != '\n') {
        printf("Try better:\n");
        rewind(stdin);
    }
    return num;
}
float methodOfInputFloat(){
    float num;
    while (scanf("%f", &num) != 1 || num <=0 ||getchar() != '\n') {
        printf("Try better:\n");
        rewind(stdin);
    }
    return num;
}
void getStr(char **string){
    int size = 0;
    int realSize = 16;
//    if ((*string) != NULL)
//        free(*string);
    *string = (char *) malloc(realSize * sizeof(char));
    rewind(stdin);
    char check;
    while (true) {
        check = getchar();
        if (check == '\n') {
            if (size + 1 < realSize) {
                *string = (char *) realloc(*string, (size + 1) * sizeof(char));
            }
            (*string)[size] = '\0';
            return;
        }

        (*string)[size] = check;
        size++;
        if (size + 1 == realSize) {
            realSize *= 2;
            *string = (char *) realloc(*string, realSize * sizeof(char));
        }
    }
}