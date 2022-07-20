//
//  Lesson_6.c
//  AlgorithmsDataStructures
//
//  Created by Михаил Киржнер on 18.07.2022.
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
//Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.

int hash(char *S)
{
    int r = 0;
    while(*S)
    {
        r+=(int)(*S);
        S++;
    }
    return r;
}

void solution1()
{
    printf("Solution 1 Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.\n");
    char *a;
    printf("Введите строку\n");
    scanf("%s", &a);
    printf("Результат: ");
    printf("%d\n", hash(a));
    
    
    printf("===================\n");
    
}

// MARK: Задание-2
// 2. Переписать программу, реализующую двоичное дерево поиска.
//а) Добавить в него обход дерева различными способами;
//б) Реализовать поиск в двоичном дереве поиска;

typedef int T;

typedef struct Node {
    T data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

// MARK: Распечатка двоичного дерева
void printTree(Node *root) {
    if (root)
    {
        printf("%d", root->data);
        if (root->left || root->right)
        {
            printf("(");
            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

// MARK: Создание нового узла
Node* getFreeNode(T value, Node *parent) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

// MARK: Вставка узла
void insert(Node **head, int value) {
    Node *tmp = NULL;
    if (*head == NULL) {
        *head = getFreeNode(value, NULL);
        return;
    }
    
    tmp = *head;
    while (tmp)
    {
        if (value > tmp->data)
        {
            if (tmp->right)
            {
                tmp = tmp->right;
                continue;
            }
            else
            {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        }
        else if (value < tmp->data)
        {
            if (tmp->left)
            {
                tmp = tmp->left;
                continue;
            }
            else
            {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
        }
        else
        {
            exit(2);
        }
    }
}

// MARK: Обход в прямом порядке
void preOrderTravers(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

// MARK: Симметричный обход
void inOrderTravers(Node* root) {
    if (root) {
        inOrderTravers(root->left);
        printf("%d ", root->data);
        inOrderTravers(root->right);
    }
}

// MARK: Обход в обратном порядке
void postOrderTravers(Node* root) {
    if (root) {
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        printf("%d ", root->data);
    }
}

// MARK: Поиск в двоичном дереве
int searchTree(Node *root, int value) {
    if (root) {
        if (root->data == value) {
            return 1;
        }
        else if(value > root->data)
        {
            if(root->right)
            {
                return searchTree(root->right, value);
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (root->left)
            {
                return searchTree(root->left, value);
            }
            else
            {
                return 0;
            }
        }
    }
    else
    {
        return 0;
    }
}

void solution2()
{
    int key = 0;
    Node *Tree = NULL;
    FILE* file = fopen("data.txt", "r");
    
    if (file == NULL)
    {
        puts("Can't open file!");
    }
    else {
        int count;
        fscanf(file, "%d", &count);
        int i;
        for (i = 0; i < count; i++)
        {
            int value;
            fscanf(file, "%d", &value);
            insert(&Tree, value);
        }
        fclose(file);
        printf("\nСкобочная запись дерева\n");
        printTree(Tree);
        printf("\n");
        
        printf("\nОбход в прямом порядке\n");
        preOrderTravers(Tree);
        printf("\n");
        
        
        printf("\nСимметричный обход\n");
        inOrderTravers(Tree);
        printf("\n");
        
        printf("\nОбход в обратном порядке\n");
        postOrderTravers(Tree);
        printf("\n");
    }
    
    printf("Введите искомое значение: ");
    scanf("%d", &key);
//    printf("\nSearch in tree (key):\n");
    if (searchTree(Tree, key))
    {
        printf("%d найдено в дереве", key);
    }
    else
    {
        printf("%d не найдено в дереве", key);
    }
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
