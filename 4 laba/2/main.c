#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "task2.h"
int main() {
    int arr[100][100], n, m;
    srand(time(NULL));

    printf("Enter the size of array (N*M/rows*columns):\n");
    printf("Enter the number of rows (less than 100): \n");
    n = inputChecking();
    printf("Enter the number of colums (less than 100): \n");
    m = inputChecking();
    input(arr, n, m);
    output(arr, n, m);

    checkingForPos(arr, n, m);
    changing(arr, n ,m);
    printf("\nFinal array:\n");
    output(arr, n, m);
    return 0;
}