#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    srand(time(NULL));
    int n, *arr, *temp, *incr, *decr;

    printf("\033[0;31mEnter the number of elements in array: \033[0m");
    n = inputChecking();

    arr = (int*) malloc(n * sizeof (int));
    temp = (int*) malloc(n * sizeof (int));
    incr = (int*) malloc(n * sizeof (int));
    decr = (int*) malloc(n * sizeof (int));
    inputRand(arr, n);

    copying(arr, temp, n);
    incrSort(arr, incr, n);
    descrSort(arr, decr, n);
    inputFinal(arr, incr, decr, n);
    //outputOfResults(results, SORTSNUM);
    //choosingSortingMethod(arr, temp, n);
    return 0;
}
