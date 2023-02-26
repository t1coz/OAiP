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
        for(int i=0; i<(*num); i++){
            printf("\n\033[0;34m%d.\033[0m Name: %s.\n", i+1, (*boilers)[i].name);
            printf("Number of loops: %d.\n", (*boilers)[i].numberOfLoops);
            printf("Thermal power: %.2lf.\n", (*boilers)[i].thermalPower);
            printf("Heating area: %d.\n", (*boilers)[i].heatingArea);
            printf("Depth: %.2f.\n", (*boilers)[i].depth);
            printf("Type of solid fuel: %s.\n", (*boilers)[i].typeOfSolidFuel);
        }
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
int compare(Boiler* f1, Boiler* f2, int field1, int field2){
    if (field1 == 1){
        if (strcmp(f1->name, f2->name) < 0){
            return -1;
        }
        else if (strcmp(f1->name, f2->name) > 0){
            return 1;
        }
    }
    else if (field1 == 2){
        if (f1->numberOfLoops < f2->numberOfLoops){
            return -1;
        }
        else if (f1->numberOfLoops > f2->numberOfLoops){
            return 1;
        }
    }
    else if (field1 == 3){
        if (f1->heatingArea < f2->heatingArea){
            return -1;
        }
        else if (f1->heatingArea > f2->heatingArea){
            return 1;
        }
    }
    else if (field1 == 4){
        if (f1->thermalPower < f2->thermalPower){
            return -1;
        }
        else if (f1->thermalPower > f2->thermalPower){
            return 1;
        }
    }
    else if (field1 == 5){
        if (f1->depth < f2->depth){
            return -1;
        }
        else if (f1->depth > f2->depth){
            return 1;
        }
    }
    else if (field1 == 6){
        if (f1->typeOfSolidFuel < f2->typeOfSolidFuel){
            return -1;
        }
        else if (f1->typeOfSolidFuel > f2->typeOfSolidFuel){
            return 1;
        }
    }
    if (field2 == 1){
        if (strcmp(f1->name, f2->name) < 0){
            return -1;
        }
        else if (strcmp(f1->name, f2->name) > 0){
            return 1;
        }
    }
    else if (field2 == 2){
        if (f1->numberOfLoops < f2->numberOfLoops){
            return -1;
        }
        else if (f1->numberOfLoops > f2->numberOfLoops){
            return 1;
        }
    }
    else if (field2 == 3){
        if (f1->heatingArea < f2->heatingArea){
            return -1;
        }
        else if (f1->heatingArea > f2->heatingArea){
            return 1;
        }
    }
    else if (field2 == 4){
        if (f1->thermalPower < f2->thermalPower){
            return -1;
        }
        else if (f1->thermalPower > f2->thermalPower){
            return 1;
        }
    }
    else if (field2 == 5){
        if (f1->depth < f2->depth){
            return -1;
        }
        else if (f1->depth > f2->depth){
            return 1;
        }
    }
    else if (field2 == 6){
        if (f1->typeOfSolidFuel < f2->typeOfSolidFuel){
            return -1;
        }
        else if (f1->typeOfSolidFuel > f2->typeOfSolidFuel){
            return 1;
        }
    }
    return 0;
}
void shellSort(Boiler* boilers, int n, int field1, int field2){
    int gap, i, j;
    Boiler temp;
    for (gap = n / 2; gap > 0; gap /= 2){
        for (i = gap; i < n; i++){
            temp = boilers[i];
            for (j = i; j >= gap && compare(&boilers[j - gap], &temp, field1, field2) > 0; j -= gap){
                boilers[j] = boilers[j - gap];
            }
            boilers[j] = temp;
        }
    }
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