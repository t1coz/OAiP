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
                    while (scanf("%d", &arr[i][j]) != 1|| arr[i][j] <= 0 || arr[i][j] > 100 || getchar() != '\n'){
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
int inputChecking(){
    float num;
    while (scanf("%f", &num) != 1 || (int)num <= 0 || num != (int)num ||num > 100 || getchar() != '\n') {

        printf("Try entering the element again: ");
        rewind(stdin);
    }
    return num;
}
void output(int arr[100][100], int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void characteristics(int arr[100][100], int* sumAr, int n, int m){
    int temp;

    for(int j=0; j<m; j++){
        sumAr[j] = 0;
        for(int i=0; i<n; i++){
            if(arr[i][j]<0 && arr[i][j]% 2 != 0) {
                sumAr[j]+=abs(arr[i][j]);
            }
        }
        printf("Characteristics of %d column: %d;\n", j+1, sumAr[j]);
    }
    for(int j=1; j<m; j++){
        for(int k = 0; k < m-j; k++){
            if(sumAr[k]>sumAr[k+1])
            {
                temp = sumAr[k];
                sumAr[k] = sumAr[k+1];
                sumAr[k+1] = temp;
                for(int i = 0; i <=n; i++)
                {
                    temp = arr[i][k];
                    arr[i][k] = arr[i][k+1];
                    arr[i][k+1] = temp;
                }
            }
        }

    }
}
void sumInRowsWP(int arr[100][100], int n, int m){
    int neg = 0, sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(arr[j][i]<0){
                neg++;
            }
        }
        if(neg > 0){
            for (int j = 0; j < m; j++) {
                sum += arr[j][i];
            }
            printf("Sum of elements in %d column: %d;\n", i+1, sum);
        }
        sum = 0;
        neg = 0;
    }
}

#ifndef INC_1_TASK1_H
#define INC_1_TASK1_H
#endif //INC_1_TASK1_H
