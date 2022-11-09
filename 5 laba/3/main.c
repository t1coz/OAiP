#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "arrays.h"
int main() {
    srand(time(NULL));
    int n, m = 1;
    int** arr;
    printf("\033[0;33mIn every even row double odd elements.\033[0m\n");
    printf("\033[0;31mEnter the number of rows in array: \033[0m");
    n = inputChecking();

    arr = memory(n, m);

    arrInput(arr, n, &m);
    printf("\n\033[0;32mInitial array:\033[0m\n");
    output(arr, n);

    doubleEl(&arr, n);

    printf("\n\033[0;32mFinal array:\033[0m\n");
    output(arr, n);

    deletingAarr(arr, n);
    return 0;
}