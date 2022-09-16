#include <stdio.h>
int main() {

    float x1, x2, y1, y2, res, root;
    printf("enter FIRST two coordinates: ");

    //ввод и проверка переменных на подходящий тип данных
    while (scanf("%f%f", &x1, &y1) != 2){
        printf("try entering the FIRST 2 coordinates again: ");
        rewind(stdin);
    }
    printf("enter SECOND two coordinates: ");
    while (scanf("%f%f", &x2, &y2) != 2){
        printf("try entering the SECOND 2 coordinates again: ");
        rewind(stdin);
    }

    //вычисление результата до использования корня
    res = ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2));

    //проверка на существование отрезка
    if(res <0){
        printf("It is impossible to calculate the distance:\nsegment does not exist.");
        return 0;
    }else if (res == 0){
        printf("Segment does not exist.");
        return 0;
    }

    //вычисление корня числа
    for(root = 0; root * root < res; root += 0.00001);

    printf("The distance between coordinates is %0.2f",root);

    return 0;
}
