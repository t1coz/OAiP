#include "boilers.h"
#include "menuCommands.h"
int main(){
    int number = 0;
    Boiler* boilers = NULL;
    //creatingTheArray(&boilers, number);
    menuInterface(&boilers, &number);
}
