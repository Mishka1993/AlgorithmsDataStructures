//
//  Lesson_7.c
//  AlgorithmsDataStructures
//
//  Created by Михаил Киржнер on 26.07.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>

void solution1(void);
void solution2(void);
void solution3(void);
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

void loadMatrix(int N, char *filename)
{
    FILE *file = fopen(filename, "r");
    int matrix[N][N];
    int i, j;
    
    if (file == NULL)
    {
        printf("Can't open file");
        exit(1);
    }
    for(i = 0; i < N && !feof(file); i++) {
        for(j = 0; j < N && !feof(file); j++) {
            fscanf(file, "%d", &matrix[i][j]);
            printf("%d ", matrix[i][j]);
        }
        putchar('\n');
        
    }
    fclose(file);
}

void solution1()
{
    printf("Solution 1 Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран.\n");
    
    
    const char* filename = "/AlgorithmsDataStructuresGB/AlgorithmsDataStructuresGB/data.txt";
    
    printf("Результат: ");
    printf("\n");
    loadMatrix(5, filename);
    
    printf("===================\n");
    
}

int G[10][10], visited[10], n;

void DFS(int i)
{
    int j;
    printf("\n%d",i);
    visited[i]=1;
    for(j = 0; j < n; j++)
        if(!visited[j] && G[i][j]==1)
            DFS(j);
}


void solution2()
{
    printf("Solution 2 Написать рекурсивную функцию обхода графа в глубину.\n");
    
    int i,j;
    printf("Введите количество вершин: ");
    
    scanf("%d",&n);
    
    printf("\nВведите матрицу смежности графа:");
    printf("\n");
    
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d",&G[i][j]);
    for(i = 0; i < n; i++)
        visited[i] = 0;
    DFS(0);
    
    printf("\n");
    printf("===================\n");
}

#define MAX 100

#define initial 1
#define waiting 2
#define visited 3

int n;
int adj[MAX][MAX];
int state[MAX];
void create_graph(void);
void BF_Traversal(void);
void BFS(int v);

int queue[MAX], front = -1, rear = -1;
void insert_queue(int vertex);
int delete_queue(void);
int isEmpty_queue(void);


void BF_Traversal(void)
{
    int v;
    for(v=0; v<n; v++)
        state[v] = initial;
    printf("Введите начальную вершину для обхода графа в ширину: \n");
    scanf("%d", &v);
    BFS(v);
}

void BFS(int v)
{
    int i;
    insert_queue(v);
    state[v] = waiting;
    while(!isEmpty_queue())
    {
        v = delete_queue( );
        printf("%d ",v);
        state[v] = visited;
        for(i=0; i<n; i++)
        {
            if(adj[v][i] == 1 && state[i] == initial)
            {
                insert_queue(i);
                state[i] = waiting;
            }
        }
    }
    printf("\n");
}

void insert_queue(int vertex)
{
    if(rear == MAX-1)
        printf("Переполнение очереди\n");
    else
    {
        if(front == -1)
            front = 0;
        rear = rear+1;
        queue[rear] = vertex ;
    }
}

int isEmpty_queue()
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int delete_queue()
{
    int delete_item;
    if(front == -1 || front > rear)
    {
        printf("Неисполнение очереди\n");
        exit(1);
    }
    delete_item = queue[front];
    front = front+1;
    return delete_item;
}

void create_graph()
{
    int count,max_edge,origin,destin;
    
    printf("Введите количество вершин: ");
    scanf("%d",&n);
    max_edge = n*(n-1);
    
    for(count=1; count<=max_edge; count++)
    {
        printf("Введите границы %d( -1 -1 для выхода ) : ",count);
        scanf("%d %d", &origin, &destin);
        
        if((origin == -1) && (destin == -1))
            break;
        
        if(origin>=n || destin>=n || origin<0 || destin<0)
        {
            printf("Недопустимые границы!\n");
            count--;
        }
        else
        {
            adj[origin][destin] = 1;
        }
    }
}

void solution3() {
    printf("Solution 3 Написать функцию обхода графа в ширину.\n");
    
    create_graph();
    BF_Traversal();
    
    
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
