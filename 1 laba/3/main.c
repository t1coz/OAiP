#include <stdio.h>
int main() {
    float first, second, third, resForNotZero, resForZero, summ;

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

    //проверка чисел на 0 и арифметическое среднее
    if ( first == 0 || second == 0 || third == 0){
        resForZero = (first + second + third)/3.0;
        printf("The arithmetic mean of these numbers is %f", resForZero);
    }else{ //геометрическое среднее
        summ = (first * second * third);
        for(resForNotZero = 0; resForNotZero*resForNotZero*resForNotZero < summ; resForNotZero+= 0.00001);
        printf("The geometric mean of these numbers is %f", resForNotZero);
    }
    return 0;
}
