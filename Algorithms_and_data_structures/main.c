//
//  main.c
//  Algorithms_and_data_structures
//
//  Created by Сергей Черных on 15.12.2021.
//

//  1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
//  2. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. Примеры правильных скобочных выражений: (), ([])(), {}(),
//  ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [, (, {.
//  Например: (2+(2*2)) или [2/{5*(4+7)}].
//  3. *Создать функцию, копирующую односвязный список (то есть создающую в памяти копию односвязного списка без удаления первого списка).
//  4. *Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.
//  5. Реализовать очередь:
//      1. С использованием массива.
//      2. *С использованием односвязного списка.
//  6. ***Реализовать двустороннюю очередь.

#include <stdio.h>
#include <stdlib.h>
#define T int
#define stackSizeInit -1

struct StackNode
{
    T value;
    struct StackNode *next;

};
typedef struct StackNode StackNode;

struct Stack
{
    StackNode *head;
    int size;
    int maxSize;
};

void pushToStack (T value, struct Stack *stack)
{
    if (stack->size + 1 >= stack->maxSize)
    {
        puts("Error stack size!");
        return;
    }

    StackNode *temp = (StackNode*) malloc(sizeof(StackNode));
    temp->value = value;
    temp->next = stack->head;
    stack->head = temp;
    stack->size++;
}

T popOfStack (struct Stack *stack)
{
    if (stack->size == 0)
    {
        puts("Stack is empty!");
        return NULL;
    }
    StackNode* next = NULL;
    T value;
    value = stack->head->value;
    next = stack->head;
    stack->head = stack->head->next;
    free(next);
    stack->size--;
    return value;
}

void printStack(struct Stack *stack)
{
    StackNode *current = stack->head;
    while (current != NULL) {
        printf("|%i| \n", current->value);
        current = current->next;
    }
}

void dec2bin(int dec)
{
    struct Stack Stack;
    Stack.size = stackSizeInit;
    Stack.maxSize = 50;
    Stack.head = NULL;

    while (dec)
    {
        pushToStack(dec % 2, &Stack);
        dec /= 2;
    }

    StackNode *current = Stack.head;
    while (current != NULL)
    {
        printf("%i", current->value);
        current = current->next;
    }
    printf("\n");
}

int main ()
{
    dec2bin(27);
    
    return 0;
}
