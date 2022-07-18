//
//  Lesson_5.c
//  AlgorithmsDataStructures
//
//  Created by Михаил Киржнер on 17.07.2022.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>



#include <stdbool.h>



#define T char
#define MaxN 1000



void solution1(void);
void solution2(void);
void solution3(void);
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
            case 0:
                printf("Bye-bye");
                break;
            default:
                printf("Wrong selected\n");
        }
    } while (sel != 0);
    return 0;
}

//1 Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.

T Stack [MaxN];

int N = -1;

void push(T i)
{
    if (N < MaxN)
    {
        N++;
        Stack[N] = i;
    }
    else
        printf("Stack overflow");
}

T pop(void)
{
    if (N != -1)
        return  Stack[N--];
    else
        printf("Stack is empty");
    return  0;
}

T c;

T find_to_bin(int decemal_nomber)
{
    if (decemal_nomber == 0)
        return 0;
    else
        
        while(decemal_nomber)
        {
            int t =  decemal_nomber %2;
            decemal_nomber = decemal_nomber/2;
            push(t);
        }
    return c;
}


void solution1()
{
    printf("Solution 1 Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.\n");
    
    int decemal_nomber;
    
    printf("Input decemal_nomber: ");
    scanf("%d", &decemal_nomber);
    find_to_bin(decemal_nomber);
    while (N != -1)
        printf("%d", pop());
    printf("\n");
    printf("===================\n");
    
}


//2. Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти.

struct TNode
{
    T value;
    struct TNode *next;
};

typedef struct TNode Node;

struct Stack2
{
    Node *head;
    int size;
    int maxSize;
};

struct Stack2 Stack2;

void push2(T value)
{
    if (Stack2.size >= Stack2.maxSize)
    {
        printf("Error stack size");
        return;
    }
    Node *tmp;
    if (!(tmp = (Node*) malloc(sizeof(Node))))
    {
        printf("Error: can't allocate memory");
        EXIT_FAILURE;
    }
    else {
        
        tmp->value = value;
        tmp->next = Stack2.head;
        Stack2.head = tmp;
        Stack2.size++;
    }
}

T pop2(void) {
    if (Stack2.size == 0)
    {
        printf("Stack is empty");
        
    }
    // Временный указатель
    Node* next = NULL;
    // Значение "наверху" списка
    T value;
    
    value = Stack2.head->value;
    next = Stack2.head;
    Stack2.head = Stack2.head->next;
    // Запись, на которую указывала голова удаляем, освобождая память
    free(next);
    // Возвращаем значение, которое было в голове
    Stack2.size--;
    return value;
}

void PrintStack(void)
{
    Node *current = Stack2.head;
    while(current != NULL)
    {
        printf("%c ", current->value);
        current = current->next;
    }
}

void solution2()
{
    printf("Solution 2 Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти.\n");
    
    Stack2.maxSize = 100;
    Stack2.head = NULL;
    push2('a');
    push2('b');
    push2('c');
    push2('d');
    push2('e');
    push2('f');
    PrintStack();
    printf("\n");
    
    printf("===================\n");
    
}


//3. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
//Например: (2+(2*2)) или [2/{5*(4+7)}]

struct stack
{
    int size;
    char * st;
};
struct stack s;
void push3(char hell)
{
    if(s.size == 0 && s.st == NULL)
    {
        s.size++;
        s.st = (char*)malloc(sizeof(char)*s.size);
        s.st[s.size-1] = hell;//добавляем в стек один эл
    }
    else
    {
       char * tmp =  s.st;
       s.size++;
       s.st = (char*)malloc(sizeof(char)*s.size);
       int i;
       for(i=0;i<s.size-1;i++)
       {
        s.st[i] = tmp[i];
       }
       free(tmp);
       s.st[s.size-1] = hell;
    }
}
char pop3(){
    char ch = s.st[s.size-1];//сохраняем верхний элемнт стека
    s.st[s.size-1] = '\0';
    s.size--;
    return ch;
}



void solution3()
{
    printf("Solution 3 Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.\n");
    
    setlocale(LC_ALL,"RUS");
      char*m = (char*)malloc(sizeof(char*)*10);
      char*temp;
      char c = 0;
      int i=-1,n=0,t=0;
      printf("Введите значение:\n");
      scanf("%s",&m);
      while(c!='\n')
      {
          i++;
          c=getchar();
          m[i+n]=c;
          if(i==9)
          {
              n=n+i+1;
              i=-1;
              temp=m;
              char* m = (char*)malloc(sizeof(char*)*(n+10));
              for(t=0;t<n+1;t++)
                  m[t]=temp[t];
          }
      }
      m[i+n] = '\0';
      int j,ok=1,k;
      char z;
      char br1[3] = { '(', '[', '{' };
      char br2[3] = { ')', ']', '}' };
      for(j=0;ok &&(*m != '\0');j++)
          for (k=0;k<3;k++)
          {
              if(*m==br1[k])
              {
                  push3(*m);
                  m++;
                  break;
              }
              if(*m==br2[k])
              {
                  z=pop3(*m);
                  if (z!=br1[k] )
                  ok=0;
                  m++;
                  break;
              }
          }
      if ( ok && (*m == 0) )
      printf("\nВыpажение пpавильное\n");
      else printf("\nВыpажение непpавильное \n");
      free(m);
      free(s.st);

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
