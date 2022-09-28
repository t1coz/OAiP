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


//output: the last version of array
    printf("Final array: \n");
    //deletingElementsAfterElement(arr, num, lastEven(arr, num));
    //output(arr, num);
    output(arr, lastEven(arr, num)+1);

    return 0;
}
