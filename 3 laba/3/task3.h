
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
void inputRand(int* arr, int n){
    for (int i = 0; i < n; i++) {
        arr[i] = rand()% (100 - (-100) + 1) + (-100);

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
void bubbleSortDecr(int* third, int num3){
    int temp;
    for (int i = 0; i < (num3 - 1); i++){
        for (int j = 0; j < num3 - i - 1; j++){
            if (third[j] < third[j + 1]) {
                temp = third[j];
                third[j] = third[j + 1];
                third[j + 1] = temp;
            }
        }
    }
}

void bubbleSortIncr(int* third, int num){
    int temp;
    for (int i = 0; i < num; i++){
        for (int j = 0; j < num - i - 1; j++){
            if (third[j] > third[j + 1]) {
                temp = third[j];
                third[j] = third[j + 1];
                third[j + 1] = temp;
            }
        }
    }
}

void finalThirdArr(int* first, int* second, int* third, int num1, int num2, int num3){
    int k = num1;
    for (int i = 0; i < num1; i++ )
    {
        third[i]=first[i];
    }
    for (int i = 0; i < num2; i++ ) {
        third[k] = second[i];
        k++;
    }
    bubbleSortDecr(third, num3);
}

#ifndef INC_1_FUNCTIONSFOREVERYTHING_H
#define INC_1_FUNCTIONSFOREVERYTHING_H

#endif //INC_1_FUNCTIONSFOREVERYTHING_H
