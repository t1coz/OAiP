#include "functionsForAnything.c"
#ifndef SPEEDOFARRAYS_SPEEDOFARRAYS_H
#define SPEEDOFARRAYS_SPEEDOFARRAYS_H
void choosingSortingMethod(int arr[], int temp[], int n);
void inputRand(int* arr, int n);
int inputChecking();
void output(int* arr, int n);

void copying(int* arr, int* temp, int n);
void filling(int arr[], int temp[], int n);
void incrSort(int arr[], int incr[], int n);
void descrSort(int arr[], int decr[], int n);
void inputFinal(int arr[], int incr[], int decr[], int n);

double timeCalculating(void (), int arr[], int n);
void bubbleSort(int* third, int num);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
#endif //SPEEDOFARRAYS_SPEEDOFARRAYS_H