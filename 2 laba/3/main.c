#include <stdio.h>
int main() {

    int num, res, fibN1 = 0, fibN2 = 1;

    //ввод и проверка переменных на подходящий тип данных
    printf("enter the number: ");
    while (scanf("%d", &num) != 1) {
        printf("try entering the number again: ");
        rewind(stdin);
    }

    //проверка числа на 0

    if (num == 0){
        printf("There's no previous number;\nThe next number is 1.");
        return 0;
    }

    //ряд чисел Фибоначчи до введённого числа
    for (int i = 1; res < num; i++) {
        res = fibN1 + fibN2;
        fibN1 = fibN2;
        fibN2 = res;
    }

    //если число не является числом Фибоначчи
    if (res != num){
        printf("You've entered not Fibonacci number.");
        return 0;
    }

    printf("The previous number is %d;\nThe following number is %d.", fibN1, num + fibN1);
    return 0;
}
