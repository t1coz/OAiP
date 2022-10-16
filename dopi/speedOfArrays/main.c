#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    srand(time(NULL));
    int n, arr[100001], temp[100001];
    double results[3];

    printf("\033[0;31mEnter the number of elements in array: \033[0m");
    n = inputChecking();
    inputRand(arr, n);
    copying(arr, temp, n);
    choosingSortingMethod(arr, temp, results, n);
    return 0;
}
