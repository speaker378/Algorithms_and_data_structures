//
//  main.c
//  Algorithms_and_data_structures
//
//  Created by Сергей Черных on 15.12.2021.
//

// 1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения
//    оптимизированной и не оптимизированной программы. Написать функции сортировки, которые
//    возвращают количество операций.
// 2. *Реализовать шейкерную сортировку.
// 3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный
//    массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.
// 4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической
//    сложностью алгоритма.

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct timeval tv1 , tv2 , dtv;
struct timezone tz;

void time_start(void)
{
    gettimeofday (&tv1, &tz);
}

long time_stop(void)
{
    gettimeofday (&tv2, &tz);
    dtv.tv_sec = tv2.tv_sec - tv1.tv_sec;
    dtv.tv_usec = tv2.tv_usec - tv1.tv_usec;
    if (dtv.tv_usec < 0)
    {
        dtv.tv_sec--;
        dtv.tv_usec += 1000000;
    }
    return dtv.tv_sec * 1000 + dtv.tv_usec / 1000;
}

void swap (int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *b ^ *a;
}

void print (int N, int *a)
{
    int i;
    for ( i = 0; i < N; i ++)
        printf ( "%6i", a [ i ]);
    printf ( "\n" );
}

void randomListGenerator (int size, int arr[])
{
    srand( (unsigned int) time(NULL) );
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
}

void simpleBubbleSort (int size, int data[])
{
    printf("Simple bubble sort of %i items \n", size);
//    puts("Array after calling simple bubble sort");
//    print(size ,data);
    int comparisons = 0, swaps = 0, worst = size * size;
    long time;
    double difference;

    time_start();
    for (int i = 0; i < size; i ++)
        for (int j = 0; j < size - 1; j++)
        {
            comparisons++;
            if ( data[j] > data[j + 1])
            {
                swaps++;
                swap (&data[j], &data[j + 1]);
            }
        }
    time = time_stop();

    difference = (double) worst / (double) swaps;
//    puts("Array after calling simple bubble sort");
//    print(size ,data);
    printf("Total comparisons: %i \n", comparisons);
    printf("Total swaps: %i \n", swaps);
    printf("Total worst case swaps: %i \n", worst);
    printf("The result is %lf times better \n", difference);
    printf("Lead time: %ld ms \n", time);
    puts("======================================\n");
}

void improvedBubbleSort (int size, int data[])
{
    printf("Improved bubble sort of %i items \n", size);
//    puts("Array after calling improved bubble sort");
//    print(size ,data);
    int comparisons = 0, swaps = 0, worst = size * size;
    long time;
    double difference;

    time_start();
    for (int i = 0; i < size; i ++)
    {
        int flag = 1;
        for (int j = 0; j < size - (i + 1); j++)
        {
                comparisons++;
                if (data[j] > data[j + 1]) {
                    flag = 0;
                    swaps++;
                    swap(&data[j], &data[j + 1]);
                }
        }
        if (flag) {
            break;
        }
    }
    time = time_stop();

    difference = (double) worst / (double) swaps;
//    puts("Array after calling improved bubble sort");
//    print(size ,data);
    printf("Total comparisons: %i \n", comparisons);
    printf("Total swaps: %i \n", swaps);
    printf("Total worst case swaps: %i \n", worst);
    printf("The result is %lf times better \n", difference);
    printf("Lead time: %ld ms \n", time);
    puts("======================================\n");
}

void shekerSort(int size, int data[])
{
    printf("Shaker sort of %i items \n", size);
//    puts("Array after calling shaker sort");
//    print(size ,data);

    int flag = 1, left = 0, right = size - 1;
    int comparisons = 0, swaps = 0, worst = size * size;
    long time;
    double difference;

    time_start();
    while ((left < right) && flag)
    {
        flag = 0;
        comparisons++;
        for (int i = left; i < right; i++)
        {
            if (data[i] > data[i + 1])
            {
                swaps++;
                swap(&data[i], &data[i + 1]);
                flag = 1;
            }
        }
        right--;
        for (int i = right; i>left; i--)
        {
            comparisons++;
            if (data[i - 1] > data[i])
            {
                swaps++;
                swap(&data[i], &data[i - 1]);
                flag = 1;
            }
        }
        left++;
    }
    time = time_stop();
    difference = (double) worst / (double) swaps;
//    puts("Array after calling shaker sort");
//    print(size ,data);
    printf("Total comparisons: %i \n", comparisons);
    printf("Total swaps: %i \n", swaps);
    printf("Total worst case swaps: %i \n", worst);
    printf("The result is %lf times better \n", difference);
    printf("Lead time: %ld ms \n", time);
    puts("======================================\n");
}

int binarysearch(int search, int data[], int size)
{
    int left, right, middle;
    left = 0;
    right = size - 1;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        if (search < data[middle])
            right = middle - 1;
        else if (search > data[middle])
            left = middle + 1;
        else
            return middle;
    }
    return -1;
}

int main (int argc , char * argv [])
{
    int size = 10000;
    int data [size];
    randomListGenerator(size, data);
    simpleBubbleSort(size, data);

    randomListGenerator(size, data);
    improvedBubbleSort(size, data);

    randomListGenerator(size, data);
    shekerSort(size, data);

    int search_value = data[(rand() % size)];
    int index_search_value = binarysearch(search_value, data, size);
    printf("Index search value: %i \n", index_search_value);

    return 0;
}
