#include <stdio.h>
#include <stdlib.h>
int **memory(int n, int m) {
    int **arr;
    arr = (int **) calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++){
        arr[i] = (int *) calloc(m, sizeof(int));
    }
    if(arr == NULL){
        printf("Memory allocation failed.");
        exit(1);
    }
    return arr;
}
int methodinputCh(){
    float num;
    while (scanf("%f", &num) != 1 || num != (int)num ||((int)num !=1 && (int)num !=2 && (int)num !=99) || getchar() != '\n') {
        printf("Try again:\n");
        rewind(stdin);
    }
    return num;
}
int inputChecking(){
    float num;
    while (scanf("%f", &num) != 1 || (int)num <= 0 || num != (int)num || getchar() != '\n') {
        printf("Try entering the number of elements again: ");
        rewind(stdin);
    }
    return num;
}
void deleting(int **arr, int n, int *m){
    for (int i = 0; i < n; i++){
        for (int k = *m-i; k < *m; k++){
            arr[i][k - 1] = arr[i][k];
        }
    }
    (*m)--;
    for (int j = 0; j < n; ++j) {
        arr[j] = (int*)realloc(arr[j], (*m) * sizeof(int));
    }
}

void input(int** arr, int n){
    int choice, br = 0;
    printf("Choose a method of filling the array:\n"
           "1. manual typing;\n"
           "2. random elements.\n"
           "\033[0;33m(Type '99' to exit the program)\033[0m\n");
    choice = methodinputCh();
    switch (choice) {
        case 1:
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    printf("Enter the element %d %d: ", i+1, j+1);
                    while (scanf("%d", &arr[i][j]) != 1 || arr[i][j] <= 0 || arr[i][j] > 100 || getchar() != '\n'){
                        printf("Try entering the %d element again: ", i+1);
                        rewind(stdin);
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    arr[i][j] = rand()% (100 - -100 + 1) + -100;
                }
            }
            break;
        case 99:
            printf("\033[0;31mThe end of the program.\033[0m");
            exit(0);
    }
}
void outputInit(int** arr, int n, int m){
    if(m == 0){
        printf("\033[0;31mArray is empty.\033[0m");
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(j == m - i - 1){
                printf("\033[0;31m%4d \033[0m", arr[i][j]);
            }else{
                printf("%4d ", arr[i][j]);
            }
        }
        printf("\n");
    }
}
void output(int** arr, int n, int m){
    if(m == 0){
        printf("\033[0;31mArray is empty.\033[0m");
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}
void deletingAarr(int **arr, int n){
    for (int i = 0; i < n; ++i) free(arr[i]);
    free(arr);
}