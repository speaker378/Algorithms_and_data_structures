//
//  main.c
//  Algorithms_and_data_structures
//
//  Created by Сергей Черных on 15.12.2021.
//
//  1. Реализовать сортировку подсчетом.
//
//  2. Реализовать быструю сортировку.
//
//  3. *Реализовать сортировку слиянием.
//
//  4. **Реализовать алгоритм сортировки со списком.

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct timeval tv1 , tv2 , dtv;
struct timezone tz;

void time_start(void) {
    gettimeofday (&tv1, &tz);
}

long time_stop(void) {
    gettimeofday (&tv2, &tz);
    dtv.tv_sec = tv2.tv_sec - tv1.tv_sec;
    dtv.tv_usec = tv2.tv_usec - tv1.tv_usec;
    if (dtv.tv_usec < 0) {
        dtv.tv_sec--;
        dtv.tv_usec += 1000000;
    }
    return dtv.tv_sec * 1000 + dtv.tv_usec / 1000;
}

void swap (int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *b ^ *a;
}

void print (int size, int* array) {
    int i;
    for (i = 0; i < size; i ++) {
        printf("%i ", array[i]);
    }
    printf("\n");
}

void createRandomArray (int size, int* array) {
    srand( (unsigned int) time(NULL) );
    for (int i = 0; i < size; i++) {
        array[i] = rand()%size;
    }
}

void countingSort(int size, int array[size]) {
    int i, j;
    int *frequencyArray = (int*)malloc(size * sizeof(int));
    
    for (i = 0; i < size; i++) {
        frequencyArray[i] = 0;
    }
    
    int value = 0;
    for (i = 0; i < size; i++) {
        value = array[i];
        frequencyArray[value]++;
    }
    
    int index = 0;
    for (j = 0; j < size; j++) {
        for (i = 0; i < frequencyArray[j]; i++) {
            array[index] = j;
            index++;
        }
    }
    free(frequencyArray);
}


int main () {
    int size = 100;
    int data [size];
    
    createRandomArray(size, data);
    print(size, data);
    countingSort(size, data);
    print(size, data);
    
    return 0;
}
