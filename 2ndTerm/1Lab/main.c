#include "boilers.h"
#include "menuCommands.h"
int main(){
    int number = 0;
    Boiler* boilers = creatingTheArray(number);
    menuInterface(boilers, &number);
}
