//
//  main.c
//  AlgorithmsDataStructures
//
//  Created by Михаил Киржнер on 01.07.2022.
//

#include <stdio.h>
#include <math.h>


void solution1(void);
void solution2(void);
void solution3(void);
void solution4(void);
void solution5(void);
void menu(void);



int main() {
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
            case 5:
                solution5();
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

//MARK: Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах.

void solution1() {
    printf("Solution 1 Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах.\n");
    
    double m, h;
    
    printf("Input m: ");
    scanf("%lf", &m);
    printf("Input h: ");
    scanf("%lf", &h);
    
    printf("BMI: %lf\n", m/pow(h, 2));
    printf("===================\n");
    
}


//MARK: Найти максимальное из четырех чисел. Массивы не использовать.
void solution2() {
    printf("Solution 2 Найти максимальное из четырех чисел. Массивы не использовать.\n");
    
    double a, b, c ,d, max;
    
    printf("Input a: ");
    scanf("%lf", &a);
    printf("Input b: ");
    scanf("%lf", &b);
    printf("Input c: ");
    scanf("%lf", &c);
    printf("Input d: ");
    scanf("%lf", &d);
    
    
    if (a > b && a > c && a > d)
        max = a;
    else
        if (b > c && b > d)
            max = b;
        else
            if (c > d)
                max = c;
            else
                max = d;
    
    
    printf("max %lf\n", max);
    printf("===================\n");
    
}

//MARK: Написать программу обмена значениями двух целочисленных переменных
void solution3() {
    printf("Solution 3 Написать программу обмена значениями двух целочисленных переменных.\n");
    
    int a, b, temp;
    
    printf("Input a: ");
    scanf("%d", &a);
    printf("Input b: ");
    scanf("%d", &b);
    
    // с использованием третьей переменной
    temp = a;
    a = b;
    b = temp;
    
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("===================\n");
    
    // без использования третьей переменной
    
    a += b;
    b = a - b;
    a -= b;
    
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("===================\n");
    
}

//MARK: Написать программу нахождения корней заданного квадратного уравнения
void solution4() {
    printf("Solution 4 Написать программу нахождения корней заданного квадратного уравнения (ax^2+bx+c=0).\n");
    
    // ax^2+bx+c=0
    
    double a, b, c;
    
    double D;
    double x1;
    double x2;
    
    printf("Input a: ");
    scanf("%lf", &a);
    printf("Input b: ");
    scanf("%lf", &b);
    printf("Input c: ");
    scanf("%lf", &c);
    
    D = pow(b,2) - (a * c * 4);
    
    if (D < 0)
    {
        printf("D<0 Уравнение не имеет корней\n");
        printf("===================\n");
    }
    if (D == 0)
    {
        x1 = -b / (2 * a);
        
        printf("D = %lf\n", D);
        printf("x1 =  %lf\n", x1);
        printf("===================\n");
    }
    if (D > 0)
    {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = ( -b - sqrt(D)) / (2 * a);
        
        printf("D = %lf\n", D);
        printf("x1 =  %lf\n", x1);
        printf("x2 =  %lf\n", x2);
        printf("===================\n");
        
    }
}

//MARK: Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
void solution5() {
    printf("Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».\n");
    
    int x, z, y;
    
    printf ("Введите свой возраст: ");
    scanf ("%d", &x);
    
    z = x % 10;
    y = x % 100;
    if (z == 1 && y != 11) {
        printf("Вам %d год\n", x);
        printf("===================\n");
    }
    else if (z >= 2 && z <= 4 && (y < 10 || y >= 20)) {
        printf("Вам %d года\n", x);
        printf("===================\n");
    }
    else {
        printf("Вам %d лет\n", x);
        printf("===================\n");
    }
}

void menu()
{
    printf("1 - task1\n");
    printf("2 - task2\n");
    printf("3 - task3\n");
    printf("4 - task4\n");
    printf("5 - task5\n");
    printf("0 - exit\n");
    printf("===================\n");
}
