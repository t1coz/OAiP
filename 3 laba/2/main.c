#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "task2.h"

int main() {
    int arr[100];
    int num, choice;
    srand(time(NULL));

    printf("Enter the number of elements in your array: ");
    while (scanf("%d", &num) != 1) {
        printf("Try entering the number of elements again: ");
        rewind(stdin);
    }
    checking(num);
    initialInput(arr, num, choice);

    output(arr, num);

//output: the last version of array
    printf("Final array: \n");
    output(arr, lastEven(arr, num)+1);

    return 0;
}
