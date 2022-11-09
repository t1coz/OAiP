#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "arrays.h"
int main() {
    srand(time(NULL));
    int n, m;
    int** arr;
    printf("\033[0;33mDeleting elements in the secondary diagonal.\033[0m\n\n");
    printf("\033[0;31mEnter the number of elements in array: \033[0m");
    n = inputChecking();
    m = n;

    arr = memory(n, m);
    input(arr, n);
    printf("\n\033[0;32mInitial array:\033[0m\n");
    outputInit(arr, n, m);

    deleting(arr, n, &m);
    printf("\n\033[0;32mFinal array:\033[0m\n");
    output(arr, n, m);
    deletingAarr(arr, n);
    return 0;
}

