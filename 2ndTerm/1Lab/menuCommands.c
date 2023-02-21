#include "menuCommands.h"
#include "boilers.h"
#include <stdlib.h>
#include <stdio.h>
void menuInterface(Boiler* boilers, int* number){
    void (*ptrMenu[])(Boiler*,int*) = {task1NewElement, task2RemoveElement,
                           task3SortByTwo, task4Print, task5Parsing,
                           task6ShowTheNumberOfElements};
    int choice;
    while(1){
        printf("\n\033[0;31mChoose what to do with the structure:\033[0m"
               "\n1. Add new element."
               "\n2. Delete existing element."
               "\n3. Sort elements by TWO characteristics."
               "\n4. Print all the elements."
               "\n5. Copy the data from the web page."
               "\n6. Show the number of elements."
               "\n\033[0;33m(Type 99 to exit the program)\033[0m\n"
               "\n\033[0;32mDecision: \033[0m");
        choice = methodOfInput(sizeof(ptrMenu)/sizeof(ptrMenu[0]));
        if (choice == 99){
            printf("\n\033[0;31mFinishing the program.\n\033[0m");
            freeArray(boilers);
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
char* getStr(){
    char* s;
    char c;
    int i = 0, n = 1;
    s = (char*)calloc(n, sizeof(char));
    while(n <= 1){
        while((c = getchar())!=EOF && c != '\n'){
            n++;
            s = (char*)realloc(s, n * sizeof(char));
            s[i] = c;
            i++;
        }
    }
    s[n] = '\0';
    return s;
}