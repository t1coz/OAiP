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
//min element
    printf("\nThe minimum element is %d.\n", arr[minElem(arr, num)]);
//summary
    printf("Summary is %d.", sumBetweenElements(arr, firstPosNum(arr, num) + 1, lastPosNum(arr, num) - 1));
    return 0;
}



