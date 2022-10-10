#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "task1.h"

int main() {
    int arr[100];
    int num, choice;
    srand(time(NULL));

//input
    printf("Enter the number of elements in your array: ");
    while (scanf("%d", &num) != 1) {
        printf("Try entering the number of elements again: ");
        rewind(stdin);
    }
    checking(num);
    initialInput(arr, num, choice);

//output: initial array
    printf("Initial array:\n");
    output(arr, num);
//min element
    printf("\nThe minimum element is %d.\n", arr[minElem(arr, num)]);
//summary
    printf("Summary: %d.", sumBetweenElements(arr, firstPosNum(arr, num) + 1, lastPosNum(arr, num) - 1));
    return 0;
}



