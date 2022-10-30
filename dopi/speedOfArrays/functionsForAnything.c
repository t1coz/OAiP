#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
//#include "functions.h"

void inputRand(int arr[], int n){
    for (int i = 0; i < n; i++) {
        arr[i] = rand()% (100 - (-100) + 1) + (-100);
    }
}
void output(int arr[], int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int arr[], int n){
    int i, j, min_idx;
    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        if(min_idx != i){
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}
void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void copying(int arr[], int temp[], int n){
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
}
void filling(int arr[], int temp[], int n){
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}
void incrSort(int arr[], int incr[], int n){
    filling(arr, incr, n);
    selectionSort(incr, n);

}
void descrSort(int arr[], int decr[], int n){
    filling(arr, decr, n);
    selectionSort(decr, n);
}
double timeCalculating(void f(), int arr[], int n){
    struct timeval start, stop;
    double secs = 0;
    gettimeofday(&start, NULL);
    f(arr, n);
    gettimeofday(&stop, NULL);
    secs = (double)(stop.tv_sec - start.tv_sec) + (double)(stop.tv_usec - start.tv_usec) / 1000000 ;
    //printf("\033[0;34mTime elapsed: %lf sec.\n\033[0m", secs);
    return secs;
}
int inputChecking(){
    float num;
    while (scanf("%f", &num) != 1 || (int)num <= 0 || num != (int)num || getchar() != '\n') {
        printf("Try again: ");
        rewind(stdin);
    }
    return num;
}
void inputFinal(int arr[], int incr[], int decr[], int n){
    printf("Results of each sorting method:\n"
           "\t\t\t\t\t\tRandom \t\t\tIncreasing \t\t\tDecreasing\n");
    printf("1. Bubble sort: \t\t%lf\t\t%lf\t\t\t%lf\n", timeCalculating(bubbleSort, arr, n), timeCalculating(bubbleSort, incr, n), timeCalculating(bubbleSort, decr, n));
    printf("2. Selec. sort: \t\t%lf\t\t%lf\t\t\t%lf\n", timeCalculating(selectionSort, arr, n), timeCalculating(selectionSort, incr, n), timeCalculating(selectionSort, decr, n));
    printf("3. Inser. sort: \t\t%lf\t\t%lf\t\t\t%lf\n", timeCalculating(insertionSort, arr, n), timeCalculating(insertionSort, incr, n), timeCalculating(insertionSort, decr, n));

}
void choosingSortingMethod(int arr[], int temp[], int n){
    int choice;
    while (choice){
        printf("\nChoose a method of sorting the array:\n"
               "1. bubble sort;\n"
               "2. selection sort;\n"
               "3. insertion sort;\n"
//               "\033[0;32m\nIn order to see rating, type 7;\n"
               "\033[0;32m\n(To exit program type 9)\n\033[0m");
        //output(arr, n);
        choice = inputChecking();
        switch (choice) {
            case 1:
                printf("\033[0;33mArray is sorting, please wait..........\n\033[0m");
                timeCalculating(bubbleSort, arr, n);
                filling(arr, temp, n);
                break;
            case 2:
                printf("\033[0;33mArray is sorting, please wait..........\n\033[0m");
                timeCalculating(selectionSort, arr, n);
                filling(arr, temp, n);
                break;
            case 3:
                printf("\033[0;33mArray is sorting, please wait..........\n\033[0m");
                timeCalculating(insertionSort, arr, n);
                filling(arr, temp, n);
                break;
//            case 7:
//                printf("Ranking of sorts last result:\n");
//                //outputOfResults(res, resSize);
//                break;
            case 9:
                printf("\033[1;31mThe end of the program.");
                exit(0);
            default:
                printf("\n\033[1;31mWrong choice. Try again\033[0m\n");
        }
    }
}
