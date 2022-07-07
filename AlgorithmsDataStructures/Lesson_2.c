//
//  Lesson_2.c
//  AlgorithmsDataStructures
//
//  Created by Михаил Киржнер on 07.07.2022.
//

#include <stdio.h>
#include <math.h>

void solution1(void);
void solution2(void);
void solution3(void);
void solution4(void);
void menu(void);

int main()
{
    int sel = 0;
    do
    {
        menu();
        scanf("%i", &sel);
        switch (sel)
        {
            case 1:
                solution1();
                break;
            case 2:
                solution2();
                break;
            case 3:
                solution3();
                break;
            case 4:
                solution4();
                break;
            case 0:
                printf("Bye-bye");
                break;
            default:
                printf("Wrong selected\n");
        }
    } while (sel != 0);
    return 0;
}

//Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.

int find_to_bin(int decemal_nomber)
{
    if (decemal_nomber == 0)
        return 0;
    else
        return (decemal_nomber %2 + 10 * find_to_bin(decemal_nomber / 2));
}

void solution1()
{
    printf("Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.\n");
    
    int decemal_nomber;
    
    printf("Input decemal_nomber: ");
    scanf("%d", &decemal_nomber);
    printf("%d\n", find_to_bin(decemal_nomber));
    
    printf("===================\n");
    
}


// Реализовать функцию возведения числа a в степень b:
//a. Без рекурсии.
//b. Рекурсивно.
//c. *Рекурсивно, используя свойство чётности степени.

int pow_1(int a, int b)
{
    int result = 1;
    
    for(int i = 0; i < b; i++)
    {
        result *= a;
    }
    return result;
    
}

void solution2()
{
    printf("Реализовать функцию возведения числа a в степень b. Без рекурсии.\n");
    
    int a;
    int b;
    
    
    printf("Input a: ");
    scanf("%d", &a);
    printf("Input b: ");
    scanf("%d", &b);
    
    printf("result: %d\n", pow_1(a, b));
    printf("===================\n");
    
}


int pow_2(int a, int b)
{
    if (b == 0)
        return 1;
    else
    {
        return pow_2(a, b - 1) * a;
    }
}

void solution3()
{
    printf("Реализовать функцию возведения числа a в степень b. Рекурсивно.\n");
    
    int a;
    int b;
    
    printf("Input a: ");
    scanf("%d", &a);
    printf("Input b: ");
    scanf("%d", &b);
    
    printf("result: %d\n", pow_2(a, b));
    printf("===================\n");
}


int binpow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b % 2 != 0)
        return binpow(a, b - 1) * a;
    else
    {
        int c = binpow(a, b / 2);
        return c * c;
    }
}

void solution4()
{
    printf("Реализовать функцию возведения числа a в степень b. Рекурсивно, используя свойство чётности степени.\n");
    int a;
    int b;
    
    printf("Input a: ");
    scanf("%d", &a);
    printf("Input b: ");
    scanf("%d", &b);
    
    printf("result: %d\n", binpow(a, b));
    printf("===================\n");
}

void menu()
{
    printf("1 - task1\n");
    printf("2 - task2\n");
    printf("3 - task3\n");
    printf("4 - task4\n");
    printf("0 - exit\n");
    printf("===================\n");
}
