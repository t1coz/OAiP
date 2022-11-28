#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main(){
    void (*ptrMenu[])() = {task1, task2};
    int choice;
    while(1){
        printf("\n\033[0;31mChoose the number of a task:\033[0m"
               "\n1. Find the most frequent word in a string;"
               "\n2. Delete all words starting with the character C from the string S "
               "\nthat are not in the string S0."
               "\n\033[0;33m(Type 99 to exit the program)\033[0m\n"
               "\n\033[0;32mDecision: \033[0m");
        choice = methodinputCh();
        if (choice == 99){
            printf("\n\033[0;31mFinishing the program.\n\033[0m");
            exit(0);
        }
        ptrMenu[choice-1]();
    }
    return 0;
}
