#include <stdio.h>
#include "functionsForEverything.h"

int main() {
    int arr[100];
    int num;

//input
    printf("Enter the number of elements in your array: ");
    scanf("%d", &num);
    if(num <= 0){
        printf("You should enter a positive number of elements.");
        return 0;
    }
    input(arr, num);
//output: initial array
    output(arr, num);
//last even
    lastEven(arr, num);
//deleting elements
    deletingElementsAfterElement(arr, num);
//output: the last version of array
    //output(arr, num);
    return 0;
}



