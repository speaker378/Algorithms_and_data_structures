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
#include <string.h>
#define T char
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
    if (stack->size == stackSizeInit)
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
        printf("|%c| \n", current->value);
        current = current->next;
    }
    printf("\n");
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

void check_brackets(char str[])
{
    struct Stack Stack;
    Stack.size = stackSizeInit;
    Stack.maxSize = 50;
    Stack.head = NULL;
    int stringSize = strlen(str);
    int wrong = 0;
    
    for (int i = 0; i <= stringSize; ++i) {
        if((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
        {
            pushToStack(str[i], &Stack);
        }
        if((str[i] == ')') || (str[i] == '}') || (str[i] == ']')) {
            char stackValue = popOfStack(&Stack);
            char value = str[i];
            if (stackValue == '(')
                if (value != ')') {
                    wrong = 1;
                    break;
                }
            if (stackValue == '{')
                if (value != '}') {
                    wrong = 1;
                    break;
                }
            if (stackValue == '[')
                if (value != ']') {
                    wrong = 1;
                    break;
                }
        }
    }
    if ((Stack.head != NULL) || wrong) {
        printf("wrong expression\n");
    } else {
        printf("right expression\n");
    }
}

void copyStack(struct Stack *from, struct Stack *to) {
    struct Stack temp;
    temp.size = stackSizeInit;
    temp.maxSize = 50;
    temp.head = NULL;
    
    StackNode *current = from->head;
    while (current != NULL) {
        pushToStack(current->value, &temp);
        current = current->next;
    }
    current = temp.head;
    while (current != NULL) {
        pushToStack(current->value, to);
        current = current->next;
    }
}



int main ()
{
    dec2bin(27);
    
    
    check_brackets("(2+(2*2))");
    check_brackets("[2/{5*(4+7))]");
    
    
    struct Stack Stack1;
    Stack1.size = stackSizeInit;
    Stack1.maxSize = 50;
    Stack1.head = NULL;
    pushToStack("a", &Stack1);
    pushToStack("b", &Stack1);
    pushToStack("c", &Stack1);
    
    struct Stack Stack2;
    Stack2.size = stackSizeInit;
    Stack2.maxSize = 50;
    Stack2.head = NULL;

    copyStack(&Stack1, &Stack2);
    printStack(&Stack1);
    printStack(&Stack2);
    
    
    return 0;
}
