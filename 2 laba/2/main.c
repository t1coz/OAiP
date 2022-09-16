#include <stdio.h>

int main() {
    int n;
    float summ;

    //проверка введенных значений на правильность введённых данных
    printf("enter the number: ");
    while (scanf("%d", &n) != 1) {
        printf("try entering the number again: ");
        rewind(stdin);
    }

    //проверка числа на <=0
    if (n<=0){
        printf("your number should be higher than 0");
        return 0;
    }

    //сумма значений
    for(int i = 1; i<=n; i++){
        summ += 1.0/i;
    }
    printf("The result is %f", summ);
    return 0;
}
