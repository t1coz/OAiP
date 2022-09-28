#include <stdio.h>
#include "functionsForEverything.h"

int main() {
    int firstDecr[100], secondIncr[100], thirdDecr[100];
    int num1, num2, num3;
//input
    printf("Enter the number of elements for the First array: ");
    scanf("%d", &num1);
    input(firstDecr, num1);
    checking(firstDecr, num1);
    printf("Enter the number of elements for the Second array: ");
    scanf("%d", &num2);
    input(secondIncr, num2);
    checking(secondIncr, num2);

    output(firstDecr, num1);
    output(secondIncr, num2);

    num3 = num1 + num2;

    finalThirdArr(firstDecr, secondIncr, thirdDecr, num1, num2, num3);
//final array
    output(thirdDecr, num3);

    return 0;
}
