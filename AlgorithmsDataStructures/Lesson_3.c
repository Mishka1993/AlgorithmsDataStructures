//
//  Lesson_3.c
//  AlgorithmsDataStructures
//
//  Created by Михаил Киржнер on 13.07.2022.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


void solution1(void);
void solution2(void);
void solution3(void);
void menu(void);

void genArrays(void);

int main(int argc, char* argv[])
{
    int sel = 0;
    
    genArrays();
    
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
            case 0:
                printf("Bye-bye");
                break;
            default:
                printf("Wrong selected\n");
        }
    } while (sel != 0);
    return 0;
}

//Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. Написать функции сортировки, которые возвращают количество операций.

// Определяем максимальный размер массива
#define MaxN 100

// Перестановка значений
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

typedef int bool;
#define true 1
#define false 0

// Распечатываем массив
void print(int N, int *a)
{
    int i;
    for (i = 0; i < N; i++)
        printf("%6i", a[i]);
    printf("\n");
}

int a[MaxN]; // создаём массив максимального размера
int b[MaxN]; // копия для сравнения алгоритмов
int c[MaxN]; // копия для сравнения алгоритмов

int countItems = 0;

void genArrays()
{
    countItems = rand() % MaxN;
    
    for (int i = 0; i < countItems; i++)
    {
        int value = rand() % MaxN;
        a[i] = value;
        b[i] = value;
        c[i] = value;
    }
}

// Алгоритм пузырьковой сортировки
int bubbleSort(int N, int *a)
{
    int count = 0;
    int j = 0;
    
    for (int i = 0; i < N; i++)
    {
        for (j = 0; j < N - 1; j++)
        {
            count++; // сравнение
            if (a[j] > a[j + 1])
            {
                count++; // перестановка
                swap(&a[j], &a[j + 1]);
            }
        }
    }
    return count;
}

// Алгоритм пузырьковой сортировки, если массив частично отсортирован(оптимизация избыточных операций)
int bubbleSortSpec(int N, int *a)
{
    int count = 0;
    int j = 0;
    
    for (int i = 0; i < N; i++)
    {
        //Эта переменная будет хранить количество перестановок в рамках текущей итерации
        int counter = 0;
        
        for (j = 0; j < N - 1; j++)
        {
            count++; // операция сравнения
            if (a[j] > a[j + 1])
            {
                count++; // операция перестановки
                swap(&a[j], &a[j + 1]);
                counter++;
            }
        }
        //Если было не больше одной перестановки
        if (counter <= 1)
            break; //Прерываем цикл (прекращаем сортировку)
    }
    return count;
}

void solution1()
{
    printf("Solution 1 Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. Написать функции сортировки, которые возвращают количество операций.\n");
    
    printf("Изначальный массив\n");
    print(countItems, a);
    
    printf("\n Количество простых операций в пузырьковом алгоритме: %d\n", bubbleSort(countItems, a));
    printf("Массив после сортировки\n");
    print(countItems, a);
    printf("\n Количество простых операций в оптимизированном пузырьковом алгоритме: %d\n", bubbleSortSpec(countItems, b));
    printf("Массив после сортировки\n");
    print(countItems, b);
    
    printf("===================\n");
    
}


// Реализовать шейкерную сортировку.

int shakerSort(int N, int *a)
{
    int left = 0;
    int right = N - 1;
    int count = 0;
    int flag = 1;  // флаг наличия перемещений
    // Выполнение цикла пока левая граница не сомкнётся с правой и пока в массиве имеются перемещения
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i < right; i++)  //двигаемся слева направо
        {
            count++;
            if (a[i] >a[i + 1]) // если следующий элемент меньше текущего,
            {             // меняем их местами
                swap(&a[i], &a[i + 1]);
                flag = 1;      // перемещения в этом цикле были
            }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (int i = right; i > left; i--)  //двигаемся справа налево
        {
            count++;
            if (a[i - 1] > a[i]) // если предыдущий элемент больше текущего, меняем их местами
            {
                swap(&a[i], &a[i - 1]);
                
                flag = 1;    // перемещения в этом цикле были
            }
        }
        left++; // сдвигаем левую границу на следующий элемент
    }
    
    return count;
}

void solution2()
{
    printf("Solution 2 Реализовать шейкерную сортировку.\n");
    printf("Изначальный массив\n");
    print(countItems, a);
    printf("\n Количество простых операций в шейкерной сортировке: %d\n", shakerSort(countItems, c));
    printf("Массив после сортировки\n");
    print(countItems, c);
    
    printf("===================\n");
}


int binary_find(int N, int *a, int key)
{
    int m;
    int l = 0;
    int r = N - 1;
    
    while (true)
    {
        if (l > r)
            return (-1); // значение не найдено
        m = l + (r - l) / 2; // определение середины
        if (a[m] < key)
            l = m + 1; // если значение среднего элемента, меньше ключа, то смотреть правую половину
        if (a[m] > key)
            r = m - 1; // если значение среднего элемента, больше ключа, то смотреть левую половину
        if (a[m] == key)
            return m; // найдено значение
    }
}

// Сортировка выбором
int selectionSort(int N, int *a)
{
    int count = 0;
    int j = 0;
    int minIndex = 0;
    for (int i = 0; i < N; i++)
    {
        minIndex = i;
        for (j = i + 1; j < N; j++)
        {
            count++;
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        count++;
        swap(&a[i], &a[minIndex]);
    }
    return count;
}

void solution3()
{
    printf("Solution 3 Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.\n");
    
    int key;
    printf("Введите искомое значение: ");
    scanf("%d", &key);
    selectionSort(countItems, c);
    print(countItems, c);
    int res = binary_find(countItems, c, key);
    
    printf("Результат: ");
    if (res == -1) printf("Элемент со значением %d не найден.\n", key);
    else printf("Элемент со значением %d найден в позиции %d.\n", key, res);
    printf("\n Количество простых операций в сортировке выбором : %d\n", shakerSort(countItems, c));
    
}

void menu()
{
    printf("1 - task1\n");
    printf("2 - task2\n");
    printf("3 - task3\n");
    printf("0 - exit\n");
    printf("===================\n");
}
