//
//  Lesson_8.c
//  AlgorithmsDataStructures
//
//  Created by Михаил Киржнер on 07.08.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>


void solution1(void);
void solution2(void);
void menu(void);



int main(int argc, char* argv[])
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
            case 0:
                printf("Bye-bye");
                break;
            default:
                printf("Wrong selected\n");
        }
    } while (sel != 0);
    return 0;
}

// MARK: Задание-1
//Реализовать сортировку подсчетом.

void methodOfCalculation(int n, int mass[], int sortedMass[])
{
    int k;
    for (int i = 0; i < n; i++)
    {
        k = 0;
        for (int j = 0; j < n; j++)
        {
            if (mass[i] > mass[j])
                k++;
        }
        sortedMass[k] = mass[i];
    }
}

void solution1()
{
    printf("Solution 1 Реализовать сортировку подсчетом.\n");
    
    int N;
    
    printf("Введите N: ");
    scanf("%d", &N);
    
    //выделение памяти под массивы
    int *mass, *sortedMass;
    mass = (int *)malloc(N * sizeof(int));
    sortedMass = (int *)malloc(N * sizeof(int));
    
    
    printf("Введите элементы массива:\n");
    for (int i = 0; i < N; i++)
        scanf("%d", &mass[i]);
    
    methodOfCalculation(N, mass, sortedMass);
    
    printf("Отсортированный массив:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", sortedMass[i]);
    
    printf("\n");
    
    //освобождение памяти
    free(mass);
    free(sortedMass);
    
    printf("===================\n");
    
}

// MARK: Задание-2
// 2. Реализовать быструю сортировку.

void qsortRecursive(int *mas, int size) {
    
    int i = 0;
    int j = size - 1;
    
    int mid = mas[size / 2];
    
    do {
        
        while(mas[i] < mid) {
            i++;
        }
        
        while(mas[j] > mid) {
            j--;
        }
        
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            
            i++;
            j--;
        }
    } while (i <= j);
    
    if(j > 0) {
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        qsortRecursive(&mas[i], size - i);
    }
}



void solution2()
{
    printf("Solution 2 Реализовать быструю сортировку.\n");
    
    int N;
    
    printf("Введите N: ");
    scanf("%d", &N);
    
    //выделение памяти под массивы
    int *mas;
    mas = (int *)malloc(N * sizeof(int));
    
    
    
    printf("Введите элементы массива:\n");
    for (int i = 0; i < N; i++)
        scanf("%d", &mas[i]);
    
    qsortRecursive(mas, N);
    
    printf("Отсортированный массив:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", mas[i]);
    
    printf("\n");
    printf("===================\n");
}



void menu()
{
    printf("1 - task1\n");
    printf("2 - task2\n");
    printf("0 - exit\n");
    printf("===================\n");
}
