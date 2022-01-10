//
//  main.c
//  Algorithms_and_data_structures
//
//  Created by Сергей Черных on 15.12.2021.
//

//  1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
//
//  2. Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти. Если память не выделяется, то выводится соответствующее сообщение. Постарайтесь создать ситуацию, когда память не будет выделяться (добавлением большого количества данных).
//
//  3. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
//  Например: (2+(2*2)) или [2/{5*(4+7)}]
//  4. *Создать функцию, копирующую односвязный список (то есть создает в памяти копию односвязного списка, не удаляя первый список).
//
//  5. **Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.
//
//  6. *Реализовать очередь.

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
};

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
};

void printStack(struct Stack *stack)
{
    StackNode *current = stack->head;
    while (current != NULL) {
        printf("|%i| \n", current->value);
        current = current->next;
    }
}

int main (int argc , char * argv [])
{
    struct Stack Stack;
    Stack.size = stackSizeInit;
    Stack.maxSize = 5;
    Stack.head = NULL;
    pushToStack(0, &Stack);
    pushToStack(1, &Stack);
    pushToStack(2, &Stack);
    pushToStack(3, &Stack);
    pushToStack(4, &Stack);
    pushToStack(5, &Stack);
    printStack(&Stack);
    popOfStack(&Stack);
    popOfStack(&Stack);
    popOfStack(&Stack);
    popOfStack(&Stack);
    popOfStack(&Stack);
    
    return 0;
}
