#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "arrays.h"

int main() {
    srand(time(NULL));
    int n;
    float *arr;

    printf("\033[0;33mIn the array delete every integer number.\033[0m\n");
    printf("\033[0;31mEnter the number of elements in array: \033[0m");
    n = inputChecking();
    arr = memory(n);

    input(arr, n);

    printf("\n\033[0;32mInitial array:\033[0m\n");
    output(arr, n);

    deleting(&arr, &n);
    printf("\n\033[0;32mFinal array:\033[0m\n");
    output(arr, n);

    free(arr);
    return 0;
}
