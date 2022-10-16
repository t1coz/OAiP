#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "task3.h"

int main() {
    int arr[100][100], n;
    srand(time(NULL));

    printf("Enter the size of array (N*N):\n");
    printf("Enter the number of rows (less than 100): \n");
    n = inputChecking();
//input
    input(arr, n);
    output(arr, n);
    summOfElemIn2Part(arr, n);
    //output(arr, n);

    return 0;
}
