void input(int arr[100][100], int n){
    int choice;
    printf("Choose a method of filling the array:\n"
           "1. manual typing;\n"
           "2. random elements.\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++) {
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
                for (int j = 0; j < n; j++) {
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
void output(int arr[100][100], int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void summOfElemIn2Part(int arr[100][100], int n){
    int limitForRows = n/2, limitForColumms = n/2, summ = 0;
    if(n % 2 != 0 && n != 1){
        limitForRows = (n/2) +1;
        //limitForColumms = (n/2)+1;
    }else if(n == 1){
        printf("There's no second quater in the array.");
        exit(0);
    }
    printf("\nElements in the second quater:\n");
    for (int i = 0; i < limitForRows; i++) {
        for (int j = limitForColumms; j < n; j++) {
            printf("%d ", arr[i][j]);
            summ += arr[i][j];
        }
        printf("\n");
    }
    printf("\nSummary of elements in the second quater: %d", summ);
}
#ifndef INC_3_TASK3_H
#define INC_3_TASK3_H
#endif //INC_3_TASK3_H
