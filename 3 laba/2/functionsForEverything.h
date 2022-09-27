
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
//1 task
int minElem(int* arr, int n){
    int index = 0;
    for (int i = 0; i < n; i++) {
        if(arr[i] < arr[index]){
            index = i;
        }
    }
    return index;
}
int firstPosNum(int* arr, int n){
    int firstPos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            firstPos = i;
            break;
        }
    }
    return firstPos;
}
int lastPosNum(int* arr, int n){
    int lastPos = 0;
    for (int i = n-1; i >= 0; i--) {
        if (arr[i] > 0) {
            lastPos = i;
            break;
        }
    }
    return lastPos;
}
int sumBetweenElements(int* arr, int first, int last){
    int summary = 0;
    while (first <= last){
        summary += arr[first];
        first++;
    }
    return summary;
}

//second task
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
void deletingElementsAfterElement(int* arr, int ind){
    for (int i = 0; i <= ind; i++) {
        printf("%d ", arr[i]);
    }
}

#ifndef INC_1_FUNCTIONSFOREVERYTHING_H
#define INC_1_FUNCTIONSFOREVERYTHING_H

#endif //INC_1_FUNCTIONSFOREVERYTHING_H
