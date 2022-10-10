#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "task3.h"

int main() {
    int firstDecr[100], secondIncr[100], thirdDecr[200];
    int num1, num2, num3, choice;
    srand(time(NULL));

//input1
    printf("Enter the number of elements in FIRST array: ");
    while (scanf("%d", &num1) != 1) {
        printf("Try entering the number of elements again: ");
        rewind(stdin);
    }
    checking(num1);
    initialInput(firstDecr, num1, choice);
//input2
    printf("Enter the number of elements in SECOND array: ");
    while (scanf("%d", &num2) != 1) {
        printf("Try entering the number of elements again: ");
        rewind(stdin);
    }
    checking(num2);
    initialInput(secondIncr, num2, choice);

//initial output
    bubbleSortDecr(firstDecr, num1);
    bubbleSortIncr(secondIncr, num2);

    printf("First array:\n");
    output(firstDecr, num1);

    printf("Second array:\n");
    output(secondIncr, num2);

//final array
    num3 = num1 + num2;

    finalThirdArr(firstDecr, secondIncr, thirdDecr, num1, num2, num3);
    printf("Final array:\n");
    output(thirdDecr, num3);
    return 0;
}
