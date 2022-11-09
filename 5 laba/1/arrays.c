#include <stdio.h>
#include <stdlib.h>
float *memory(int n){
    float *arr;
    arr = (float*)malloc(n * sizeof(float));
    if(arr == NULL)
    {
        printf("Memory allocation failed.");
        exit(1);
    }
    return arr;
}
void deleting(float** arr, int* n){
    for (int i = 0; i <(*n); i++){
        if((*arr)[i] == (int)(*arr)[i]){
            for(int k = i; k < (*n)-1; k++) {
                (*arr)[k] = (*arr)[k+1];
            }
            (*arr)[*n-1] = 0;
            (*n)--;
            *arr = realloc(*arr, (*n) * sizeof(float));
            i--;
        }
    }
}
void input(float* arr, float n){
    for (int i = 0; i < n; i++){
        printf("Enter the element %d: ", i+1);
        while (scanf("%f", &arr[i]) != 1 || getchar() != '\n'){
            printf("Try entering the %d element again: ", i+1);
            rewind(stdin);
        }
    }
}
int inputChecking(){
    float num;
    while (scanf("%f", &num) != 1 || (int)num <= 0 || num != (int)num || num > 100 || getchar() != '\n') {
        printf("Try entering the element again: ");
        rewind(stdin);
    }
    return num;
}

void output(float* arr, int n){
    if (n == 0){
        printf("\033[0;31mArray is empty.\033[0m");
    }
    for (int i = 0; i < n; i++) {
        if(arr[i] == (int)arr[i]){
            printf("\033[0;31m%f \033[0m", arr[i]);
        }else{
            printf("%f ", arr[i]);
        }
    }
    printf("\n");
}