#include "lab.h"

int main()
{
int d;
int x;

do
{
    printf("Введите номер лабы\n");
    scanf ("%d",&x);
    switch(x)
        {
        case 1:
            lab1();
            break;

        case 2:
            lab2();
            break;

        case 3:
            lab3();
            break;

        case 4:
            lab4();
            break;

        case 5:
            lab5();
            break;

        case 6:
            lab6();
            printf("Доп задания нет");
            break;

        default:
            printf("Такой лабы нет\n");
        }
    } 
    while(x>=1 && x<=6);
    return 0;
}