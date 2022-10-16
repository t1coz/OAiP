int inputChecking(){
    float num;
    while (scanf("%f", &num) != 1 || (int)num <= 0 || num != (int)num ||num > 100 || getchar() != '\n') {

        printf("Try entering the element again: ");
        rewind(stdin);
    }
    return num;
}

void input(int arr[100][100], int n, int m){
    int choice;
    printf("Choose a method of filling the array:\n"
           "1. manual typing;\n"
           "2. random elements.\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++) {
                    printf("Enter the element %d %d: ", i+1, j+1);
                    while (scanf("%d", &arr[i][j]) != 1) {
                        printf("Try entering the %d %d element again: ", i+1, j+1);
                        rewind(stdin);
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    arr[i][j] = rand()% (100 - (-100) + 1) + (-100);
                }
            }
            break;
        default:
            printf("Wrong choice.");
            exit(0);
    }
}

 void output(int arr[100][100], int n, int m){
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
             printf("%d ", arr[i][j]);
         }
         printf("\n");
     }
}


int checkingForPos(int arr[100][100], int n, int m){
    int pos = 0, rowsWithPos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(arr[i][j]>=0){
                pos++;
            }
        }
        if(pos > 0){
            rowsWithPos++;
        }
        pos = 0;
    }
    return rowsWithPos;
}

void changing(int arr[100][100], int n, int m){
    if(checkingForPos(arr, n ,m)==n){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = -arr[i][j];
            }
        }
    }else{
        printf("No positive elements in each row.\n");

    }
}
#ifndef INC_2_TASK2_H
#define INC_2_TASK2_H

#endif //INC_2_TASK2_H
