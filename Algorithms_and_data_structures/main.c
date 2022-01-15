//
//  main.c
//  Algorithms_and_data_structures
//
//  Created by Сергей Черных on 15.12.2021.
//
//
//  1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран.
//
//  2. Написать рекурсивную функцию обхода графа в глубину.
//
//  3. Написать функцию обхода графа в ширину.
//
//  4. *Создать библиотеку функций для работы с графами.

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#define VERTEX 10
#define PATH "/Users/sergejcernyh/Desktop/matrix.txt"

void createMatrix(int size, int* matrix[size][size], int min, int max) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i == j) {
                matrix[i][j] = 0;
            } else {
                int value = min + rand()%(max - min + 1);
                value = (value%2==0 || value%3==0 || value%5==0) ? 0 : value;
                matrix[i][j] = value;
                matrix[j][i] = value;
            }
        }
    }
}

void writeMatrixInFile(char* path, int size, int* matrix[size][size]) {
    FILE* file = fopen(path, "w");
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
                fprintf(file, "%i ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}


void scanfMatrix(char* path, int size, int* matrix[size][size]) {
    FILE* file = fopen(path, "r");
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);
}


void printMatrix(int size, int* matrix[size][size]) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }
}

void dfs(int* matrix[VERTEX][VERTEX], int mark[VERTEX], int v) {
     int i;
     mark[v] = 1;
     printf("%d ", v + 1);
    
     for (i = 0; i < VERTEX; i++) {
         if (matrix[v][i] != 0 && mark[i] == 0) {
             printf("-> ");
             dfs(matrix, mark, i);
         }
     }
 }

void bfs(int* matrix[VERTEX][VERTEX], int mark[VERTEX], int vertex) {

    Queue* queue = createQueue();
    enQueue(queue, vertex);
    mark[vertex] = 1;
    
    while (!queueIsEmpty(queue)) {
        int currentV = deQueue(queue);
        printf("%i -> [", currentV);
        
        if (mark[currentV] == 1) {
            for (int i = 0; i < VERTEX; i++) {
                if (matrix[currentV][i] != 0 && mark[i] == 0) {
                    enQueue(queue, i);
                    mark[i] = 1;
                    printf(" %i ", i);
                }
            }
            printf("]\n");
        }
    }
}

int main () {
    int* matrix[VERTEX][VERTEX];
    createMatrix(VERTEX, matrix, 0, 12);
    writeMatrixInFile(PATH, VERTEX, matrix);
    scanfMatrix(PATH, VERTEX, matrix);
    printMatrix(VERTEX, matrix);
    
    
    int mark[VERTEX];
    for (int i = 0; i < VERTEX; i++) {
        mark[i] = 0;
       }
    dfs(matrix, mark, 0);
    printf("\n");
    
    
    for (int i = 0; i < VERTEX; i++) {
        mark[i] = 0;
       }
    bfs(matrix, mark, 0);

    return 0;
}
