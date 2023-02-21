#include <stdlib.h>
#include "boilers.h"
#include "menuCommands.h"
Boiler *creatingTheArray(int number){
    Boiler* boilers;
    boilers = malloc(number * sizeof(*boilers));
    if(boilers == NULL){
        printf("Memory allocation failed.");
        exit(1);
    }
    return boilers;
}
void printBoilers(Boiler* boilers, int* num){
    if((*num) == 0){
        printf("\n\033[0;33mThere is no elements in the struct.\033[0m\n");
    }else{
        for(int i=0; i<(*num); i++)
            printBoilersCharacteristics(boilers, i);
    }
}
void printBoilersCharacteristics(Boiler* boilers, int i){
    printf("\n%d. %s\n", i+1, boilers[i].name);
    printf("Number Of Loops: %d\n", boilers[i].numberOfLoops);
    printf("Thermal Power: %.1lf\n", boilers[i].thermalPower);
    printf("Heating Area: %d\n", boilers[i].heatingArea);
    printf("Depth: %.1f\n", boilers[i].depth);
    printf("Type Of Solid Fuel: %s\n", boilers[i].typeOfSolidFuel);
    printf("--------------------------------------------------\n");
}
void addNewBoiler(Boiler** boilers, int* num){
    int newSize = *num + 1;
    Boiler *temp = realloc(*boilers, (newSize * sizeof(*temp)));
    if (temp == NULL){
        printf("Cannot allocate more memory.\n");
        exit(0);
    }else{
        *boilers = temp;
    }
    //*boilers = realloc(*boilers, (newSize * sizeof(Boiler)));
    printf("Name: ");
    char* elementName = getStr();
    printf("Number of loops: (1 OR 2): ");
    int loops = methodOfInput(2);
    printf("Thermal power: ");
    double thermalPower = methodOfInputDouble();
    printf("Heating area (integer): ");
    int heatingArea = methodOfInputInt();
    printf("Depth: ");
    float depth = methodOfInputFloat();
    printf("Type of solid fuel: ");
    char* typeOfSolidFuel = getStr();
    (*boilers)[*num].name = elementName;
    (*boilers)[*num].numberOfLoops = loops;
    (*boilers)[*num].thermalPower = thermalPower;
    (*boilers)[*num].heatingArea = heatingArea;
    (*boilers)[*num].depth = depth;
    (*boilers)[*num].typeOfSolidFuel = typeOfSolidFuel;
    (*num)++;
}
void showTheNumberOfElements(int num){
    printf("\n\033[0;33mNumber of elements: %d.\033[0m\n", num);
}
void removingElement(Boiler** boilers, int* num, int position){
    for(int i = position; i < (*num)-1; i++) {
        (*boilers)[i] = (*boilers)[i + 1];
    }
    (*num)--;
   *boilers = (Boiler*)realloc((*boilers), (*num) * sizeof(**boilers));
}
void freeArray(Boiler* boilers){
    free(boilers);
}
//int compare(const void *a, const void *b){
//    Boiler *x = (Boiler *)a,
//            *y = (Boiler *)b;
//    if (x->num != y->num)
//        return (x->num > y->num) - (x->num < y->num);
//    return (x->val > y->val) - (x->val < y->val);
//}