#include <stdio.h>
int main() {

    float first, second, third, pairs;

    //ввод и проверка переменных на подходящий тип данных
    printf("enter FIRST number: ");
    while (scanf("%f", &first) != 1){
        printf("try entering the FIRST number again: ");
        rewind(stdin);
    }
    printf("enter SECOND number: ");
    while (scanf("%f", &second) != 1){
        printf("try entering the SECOND number again: ");
        rewind(stdin);
    }
    printf("enter THIRD number: ");
    while (scanf("%f", &third) != 1){
        printf("try entering the THIRD number again: ");
        rewind(stdin);
    }

    pairs = 0;

    //подсчёт пар совпадающих чисел
    if(first == second){
        printf("the first number is the same as the second.\n");
        pairs++;
    }
    if (first == third){
        printf("the first number is the same as the third.\n");
        pairs++;
    }
    if (second == third){
        printf("the second number is the same as the third.\n");
        pairs++;
    }
    if(pairs == 0){
        printf("there is no equal pairs.");
    }
    return 0;
}

