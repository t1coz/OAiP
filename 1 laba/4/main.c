#include <stdio.h>

int main() {
    int num;

    //ввод и проверка переменных на подходящий тип данных
    printf("enter the number: ");
    while (scanf("%d", &num) != 1){
        printf("try entering the number again: ");
        rewind(stdin);
    }

    //вывод названия числа
    switch (num) {
        case 0: printf("Your number is zero");
            break;
        case 1: printf("Your number is one");
            break;
        case 2: printf("Your number is two");
            break;
        case 3: printf("Your number is three");
            break;
        case 4: printf("Your number is four");
            break;
        case 5: printf("Your number is five");
            break;
        case 6: printf("Your number is six");
            break;
        case 7: printf("Your number is seven");
            break;
        case 8: printf("Your number is eight");
            break;
        case 9: printf("Your number is nine");
            break;
        case 10: printf("Your number is ten");
            break;
        default:
            printf("You should enter number in range [0, 10)");
    }
    return 0;
}
