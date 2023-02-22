#include <stdlib.h>
#include <string.h>
#include "boilers.h"
#include "menuCommands.h"
void creatingTheArray(Boiler **boilers, int num){
    *boilers = (Boiler *) malloc(num * sizeof(Boiler));
    for (int i = 0; i < num; i++) {
        (*boilers)[i].name = NULL;
        (*boilers)[i].numberOfLoops = 0;
        (*boilers)[i].heatingArea = 0;
        (*boilers)[i].thermalPower = 0;
        (*boilers)[i].depth = 0;
        (*boilers)[i].typeOfSolidFuel = NULL;
    }
}
void printBoilers(Boiler** boilers, const int* num){
    if((*num) == 0){
        printf("\n\033[0;33mThere is no elements in the struct.\033[0m\n");
    }else{
        //printf("№\tname\tloops\tthermalPower\theatingArea\tdepth\ttypeOfSolidFuel\t\n");
        for(int i=0; i<(*num); i++)
            printf("%d.%4s\t%4d\t%4.2lf\t%4d\t%4.2f\t%4s\t\n", i+1, (*boilers)[i].name, (*boilers)[i].numberOfLoops,
                   (*boilers)[i].thermalPower, (*boilers)[i].heatingArea,
                   (*boilers)[i].depth, (*boilers)[i].typeOfSolidFuel);
    }
}
void addNewNumberOfBoilers(Boiler** boilers, int num){
    char* temporaryFillingArray = NULL;
    for (int i = 0; i < num; ++i) {
        printf("\n\033[0;34mEnter data for element \033[0m%d:\n", i + 1);
        printf("Name: ");
        getStr(&temporaryFillingArray);
        (*boilers)[i].name = (char*)malloc(strlen(temporaryFillingArray)+1);
        if((*boilers)[i].name){
            strcpy((*boilers)[i].name, temporaryFillingArray);
        }
        //(*boilers)[i].name[strlen(temporaryFillingArray)]='\0';
        printf("Number of loops: (1 OR 2): ");
        int loops = methodOfInput(2);
        (*boilers)[i].numberOfLoops = loops;

        printf("Thermal power: ");
        double thermalPower = methodOfInputDouble();
        (*boilers)[i].thermalPower = thermalPower;

        printf("Heating area (integer): ");
        int heatingArea = methodOfInputInt();
        (*boilers)[i].heatingArea = heatingArea;

        printf("Depth: ");
        float depth = methodOfInputFloat();
        (*boilers)[i].depth = depth;

        printf("Type of solid fuel: ");
        getStr(&temporaryFillingArray);
        (*boilers)[i].typeOfSolidFuel = malloc(strlen(temporaryFillingArray)+1);
        if((*boilers)[i].typeOfSolidFuel){
            strcpy((*boilers)[i].typeOfSolidFuel, temporaryFillingArray);
        }
        //(*boilers)[i].typeOfSolidFuel[strlen(temporaryFillingArray)]='\0';
        free(temporaryFillingArray);
    }
}
void addNewBoiler(Boiler** boilers, const int* num){
    int lastIndex = (*num) - 1;
    char* temporaryFillingArray = NULL;
    printf("Name: ");
    getStr(&temporaryFillingArray);
    (*boilers)[lastIndex].name = (char*)malloc(strlen(temporaryFillingArray) + 1);
    if((*boilers)[lastIndex].name){
        strcpy((*boilers)[lastIndex].name, temporaryFillingArray);
    }
    //(*boilers)[lastIndex].name[strlen(temporaryFillingArray)]='\0';

    printf("Number of loops: (1 OR 2): ");
    int loops = methodOfInput(2);
    (*boilers)[lastIndex].numberOfLoops = loops;

    printf("Thermal power: ");
    double thermalPower = methodOfInputDouble();
    (*boilers)[lastIndex].thermalPower = thermalPower;

    printf("Heating area (integer): ");
    int heatingArea = methodOfInputInt();
    (*boilers)[lastIndex].heatingArea = heatingArea;

    printf("Depth: ");
    float depth = methodOfInputFloat();
    (*boilers)[lastIndex].depth = depth;

    printf("Type of solid fuel: ");
    getStr(&temporaryFillingArray);
    (*boilers)[lastIndex].typeOfSolidFuel = malloc(strlen(temporaryFillingArray) + 1);
    if((*boilers)[lastIndex].typeOfSolidFuel){
        strcpy((*boilers)[lastIndex].typeOfSolidFuel, temporaryFillingArray);
    }
    //(*boilers)[lastIndex].typeOfSolidFuel[strlen(temporaryFillingArray)]='\0';
    free(temporaryFillingArray);
}
void showTheNumberOfElements(int num){
    printf("\n\033[0;33mNumber of elements: %d.\033[0m\n", num);
}
void removingElement(Boiler** boilers, int* num, int position){
    for(int i = position; i < (*num)-1; i++) {
        (*boilers)[i] = (*boilers)[i + 1];
    }
    (*num)--;
    *boilers = (Boiler*)realloc((*boilers), (*num) * sizeof(Boiler));
}
void resizeStruct(Boiler **boilers, int* num){
    (*num)++;
    *boilers = (Boiler*)realloc(*boilers, (*num) * sizeof (Boiler));
    (*boilers)[*num-1].name = NULL;
    (*boilers)[*num-1].typeOfSolidFuel = NULL;
}
void freeStructAndArray(Boiler **boilers, int num){
    for (int i = 0; i < num; i++) {
        free((*boilers)[i].name);
        free((*boilers)[i].typeOfSolidFuel);
    }
    free(*boilers);
    *boilers = NULL;
}
int compare(const void *a, const void *b){
    Boiler *x = (Boiler *)a, *y = (Boiler *)b;
    if (x->name != y->name)
        return (x->name > y->name) - (x->name < y->name);
    return (x->numberOfLoops > y->numberOfLoops) - (x->numberOfLoops < y->numberOfLoops);
}