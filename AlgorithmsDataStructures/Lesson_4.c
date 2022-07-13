//
//  Lesson_4.c
//  AlgorithmsDataStructures
//
//  Created by Михаил Киржнер on 13.07.2022.
//

#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 8
#define M 8
#define L 20
#define K 20

void solution1(void);
void solution2(void);
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
            case 0:
                printf("Bye-bye");
                break;
            default:
                printf("Wrong selected\n");
        }
    } while (sel != 0);
    return 0;
}

//Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.


void Print(int n, int m, int a[N][M])
{
    int i, j;
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}

void solution1()
{
    printf("Solution 1 Реализовать чтение массива с препятствием и нахождение количество маршрутов.\n");
    
    int A[N][M];
    
    int map[N][M] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 1, 1, 1},
        {0, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0}
    };
    
    int i, j;
    
    for(j = 0; j < M; j++)
        A[0][j] = 0;
    
    for(i = 1; i < N; i++)
    {
        if (map[i][0] == 0)
            A[i][0] = 0;
        else
            A[i][0] = 1;
        
        for(j = 1; j < M; j++)
            if (map[i][j] == 0)
                A[i][j] = 0;
            else
                A[i][j] = A[i][j - 1] + A[i - 1][j];
    }
    
    Print(N, M, A);
    
    
    printf("===================\n");
    
}


// Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.

int i, j, m, n, c[L][K];
char x[L], y[K], b[L][K];

void Print2(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 'c')
    {
        Print2(i - 1, j -1);
        printf("%c", x[i - 1]);
    }
    else if (b[i][j] == 'u')
        Print2(i - 1, j);
    else
        Print2(i, j - 1);
}

void Print3(int n, int m, int a[L][K])
{
    int i, j;
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}

void Print4(int n, int m, char a[L][K])
{
    int i, j;
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            printf(" %c ", a[i][j]);
        printf("\n");
    }
}


void lcs(void)
{
    m = strlen(x);
    n = strlen(y);
    
    for (i = 0; i <= m; i++)
        c[i][0] = 0;
    for (i = 0; i <= n; i++)
        c[0][i] = 0;
    
    
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'c';
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u';
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
        }
}

void solution2()
{
    printf("Solution 2 Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.\n");
    
    printf("Enter 1st sequence:");
    scanf("%s", x);
    printf("Enter 2nd sequence:");
    scanf("%s", y);
    printf("\nThe Longest Common Subsequence is ");
    lcs();
    Print2(m, n);
    printf("\n");
    Print3(m, n, c);
    printf("\n");
    Print4(m, n, b);
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
