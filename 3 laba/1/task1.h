
void input(int* arr, int n){
    for (int i = 0; i < n; i++) {
        printf("Enter the element %d: ", i+1);
        while (scanf("%d", &arr[i]) != 1) {
            printf("Try entering the %d element again: ", i+1);
            rewind(stdin);
        }
    }
}
void inputRand(int* arr, int n){
    for (int i = 0; i < n; i++) {
        arr[i] = rand()% (100 - -100 + 1) + -100;

    }
}
int initialInput(int* arr, int num, int choice){
    printf("Choose the method of entering elements: \n"
           "1. Manual typing;\n"
           "2. Random numbers.\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            input(arr, num);
            break;
        case 2:
            inputRand(arr, num);
            break;
        default: printf("Wrong choice.");
            exit(0);
    }
    return num;
}

void checking(num){
    if(num <= 0){
        printf("You should enter a positive number of elements.");
        exit(0);
    }
}

void output(int* arr, int n){
    for (int j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }
}
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


#ifndef INC_1_FUNCTIONSFOREVERYTHING_H
#define INC_1_FUNCTIONSFOREVERYTHING_H

#endif //INC_1_FUNCTIONSFOREVERYTHING_H
