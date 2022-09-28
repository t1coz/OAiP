
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
void checking(num){
    if(num <= 0){
        printf("You should enter a positive number of elements.");
        return;
    }
}
void bubbleSort(int* third, int num3){
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
    bubbleSort(third, num3);
}

#ifndef INC_1_FUNCTIONSFOREVERYTHING_H
#define INC_1_FUNCTIONSFOREVERYTHING_H

#endif //INC_1_FUNCTIONSFOREVERYTHING_H
