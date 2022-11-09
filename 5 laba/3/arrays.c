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
int sizeM(int **arr, int row){
    int size = 1;
    for (int i = 0; ; i++) {
        if(arr[row][i] != -100){
            size++;
        }else{
            break;
        }
    }
    return size;
}
void doubleEl(int ***arr, int n){
    int m;
    for (int i = 0; i < n; i++) {
        m = sizeM(*arr, i);
        if ((i+1) % 2 == 0 && m !=0){
            for (int j = 0; j < m;){
                if ((*arr)[i][j] % 2 != 0){
                    m++;
                    (*arr)[i] = realloc((*arr)[i], m * sizeof(int));
                    for (int k = m-1; k > j;k--){
                        (*arr)[i][k] = (*arr)[i][k-1];
                    }
                    j+=2;
                }else{
                    j++;
                }
            }
        }
    }
}
void arrInput(int** arr, int n, int *m){
    int answer, exitt;
    for (int i = 0; i < n; i++){
        exitt = 1;
        printf("Enter \033[0;33m'-100'\033[0m to go to the next row:\n");
        for (int j = 0; (j < *m) && exitt == 1; j++){
            printf("Enter the element %d %d: ", i+1, j+1);
            while (scanf("%d", &arr[i][j]) != 1 || getchar() != '\n'){
                if (arr[i][j] == -100){
                    break;
                }
                printf("Try entering the %d %d element again: ", i + 1, j + 1);
                rewind(stdin);
            }
            answer = arr[i][j];
            if (answer == -100){
                exitt = 0;
                if (i != n-1){
                    printf("\033[0;36mNew row:\n\033[0m");
                }
            }else{
                (*m)++;
                arr[i] = (int*)realloc(arr[i], (*m) * sizeof(int));
            }
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
void output(int** arr, int n){
    for (int i = 0; i < n; i++) {
        if((i+1)%2 == 0){
            printf("\033[0;31m%d.\033[0m ", i+1);
        }else{
            printf("\033[0;32m%d.\033[0m ", i+1);
        }
        for (int j = 0; j < sizeM(arr, i); j++) {
//            if (arr[i][j] == -100 && (sizeM(arr, i) == 0)){
//                printf("Row is empty");
//                break;
//            }
            if(arr[i][j] == -100){
                printf("\033[0;33m%4d.\033[0m ", arr[i][j]);
                break;
            }
            if(j == sizeM(arr, i) - 1){
                printf("\033[0;34m%4d.\033[0m ", arr[i][j]);
            }else{
                printf("\033[0;34m%4d;\033[0m ", arr[i][j]);
            }
        }
        printf("\n");
    }
}
void deletingAarr(int **arr, int n){
    for (int i = 0; i < n; ++i) free(arr[i]);
    free(arr);
}

