#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<sys/time.h>
//#include "functions.h"

void inputRand(int* arr, int n){
    for (int i = 0; i < n; i++) {
        arr[i] = rand()% (100 - (-100) + 1) + (-100);
    }
}
void output(int* arr, int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n){
    int i, j, min_idx;
    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                //checking and swapping adjacent elements when left_elem > right_elem
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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
int timeCalculating(void f(), int arr[], int n){
    struct timeval start, stop;
    double secs = 0;
    gettimeofday(&start, NULL);
    f(arr, n);
    gettimeofday(&stop, NULL);
    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    printf("\033[0;34mTime elapsed: %lf sec.\n\033[0m", secs);
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
void choosingSortingMethod(int arr[], int temp[], double res[], int n){
    int choice;
    while (choice){
        printf("\nChoose a method of sorting the array:\n"
               "1. bubble sort;\n"
               "2. selection sort;\n"
               "3. insertion sort;\n"
               "(To exit program type 9)\n");
        choice = inputChecking();
        switch (choice) {
            case 1:
                printf("\033[0;33mArray is sorting, please wait..........\n\033[0m");
                res[0] = timeCalculating(bubbleSort, arr, n);
                filling(arr, temp, n);
                break;
            case 2:
                printf("\033[0;33mArray is sorting, please wait..........\n\033[0m");
                res[1] = timeCalculating(selectionSort, arr, n);
                filling(arr, temp, n);
                break;
            case 3:
                printf("\033[0;33mArray is sorting, please wait..........\n\033[0m");
                res[2] = timeCalculating(insertionSort, arr, n);                filling(arr, temp, n);
                break;
            case 9:
                printf("\033[1;31mThe end of the program.");
                exit(0);
            default:
                printf("Wrong choice. Try again");

        }
    }
}
