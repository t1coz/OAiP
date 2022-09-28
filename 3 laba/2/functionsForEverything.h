
void input(int* arr, int n){
    for (int i = 0; i < n; i++) {
        printf("Enter the element %d: ", i+1);
        while (scanf("%d", &arr[i]) != 1) {
            printf("Try entering the %d element again: ", i+1);
            rewind(stdin);
        }
    }
}
void output(int* arr, int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int lastEven(int* arr, int n){
    int lastEvenIndex = 0;
    for (int i = n-1; i >= 0; i--) {
        if (arr[i] % 2 == 0) {
            lastEvenIndex = i;
            break;
        }
    }
    return lastEvenIndex;
}
int deletingElementsAfterElement(int* arr, int num, int ind){
    for(int i = 1; i<=num; i++){
        arr[ind+i] = 0;
    }
    num--;
    return num;
}

#ifndef INC_1_FUNCTIONSFOREVERYTHING_H
#define INC_1_FUNCTIONSFOREVERYTHING_H

#endif //INC_1_FUNCTIONSFOREVERYTHING_H
