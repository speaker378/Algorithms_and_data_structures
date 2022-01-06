//
//  main.c
//  Algorithms_and_data_structures
//
//  Created by Сергей Черных on 15.12.2021.
//
//
//  1. *Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.
//  Например, карта: 3x3
//  1 1 1
//  0 1 0
//  0 1 0
//  2. Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.
//  3. ***Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по одному разу. Здесь алгоритм решения такой же как и в задаче о 8 ферзях. Разница только в проверке положения коня.


#include <stdio.h>
#define row 5
#define column 5

void print (int n, int m, int a[row][column])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void task1 (int field[row][column], int map[row][column])
{
    int i, j, value = 1;
    
    for (j = 0; j < column; j ++)
    {
        if (map[0][j] == 0)
        {
            value = 0;
        }
        field[0][j] = value;
    }
    
    value = 1;
    for (i = 1; i < row; i ++)
    {
        if (map[i][0] == 0)
        {
            value = 0;
        }
        field[i][0] = value;
        
        for (j = 1; j < column; j ++)
        {
            if (map[i][j] == 0)
            {
                field[i][j] = 0;
            }
            else
            {
                field[i][j] = field[i][j - 1] + field[i - 1][j];
            }
            
        }
    }
}


int main (int argc , char * argv [])
{
    int A[row][column];
    int MAP[row][column] = {
        {1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1},
    };
    
    task1(A, MAP);
    print(row, column, A);
    
    return 0;
}
