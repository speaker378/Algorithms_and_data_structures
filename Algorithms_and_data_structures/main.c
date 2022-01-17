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

void quickSort (int* array, int left, int right) {
    int i = left;
    int j = right;
    int pivot = array[(left + right)/2];
    
    while (i <= j) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        
        if (i <= j) {
            if (array[i] > array[j]) {
                swap(&array[i], &array[j]);
            }
            i++;
            j--;
        }
    }
    
    if (left < j) quickSort (array, left, j);
    if (i < right) quickSort (array, i, right);
}


void merge(int* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main () {
    long time;
    int size = 1000000;
    int data [size];
    
    createRandomArray(size, data);
//    print(size, data);
    
    time_start();
    countingSort(size, data);
    time = time_stop();
    printf("Counting sort for %i items - %li ms\n", size, time);
//    print(size, data);
//    puts("");
    
    
    createRandomArray(size, data);
//    print(size, data);
    
    time_start();
    quickSort(data, 0, size - 1);
    time = time_stop();
    printf("Quick sort for %i items - %li ms\n", size, time);
//    print(size, data);
//    puts("");
    
    createRandomArray(size, data);
//    print(size, data);
    
    time_start();
    mergeSort(data, 0, size - 1);
    time = time_stop();
    printf("Merge sort for %i items - %li ms\n", size, time);
//    print(size, data);
//    puts("");
    
    return 0;
}
