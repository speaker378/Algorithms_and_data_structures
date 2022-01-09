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
#include <string.h>

void print (int row, int column, int a[row][column])
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void task1 (int m, int n, int field[m][n], int map[m][n])
{
    int i, j, value = 1;
    
    for (j = 0; j < n; j ++)
    {
        if (map[0][j] == 0)
        {
            value = 0;
        }
        field[0][j] = value;
    }
    
    value = 1;
    for (i = 1; i < m; i ++)
    {
        if (map[i][0] == 0)
        {
            value = 0;
        }
        field[i][0] = value;
        
        for (j = 1; j < n; j ++)
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


int max(int a, int b)
{
    return a > b ? a : b;
}

void lcs(char *X, char *Y, int m, int n)
{
    int L[m+1][n+1];
    
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    
    int index = L[m][n];
    
    char lcs[index+1];
    
    int i = m, j = n;
    
    while (i > 0 && j > 0)
    {
        if (X[i-1] == Y[j-1])
        {
            lcs[index-1] = X[i-1];
            i--; j--; index--;
        }
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
    
    print(m + 1, n + 1, L);
    printf("LCS: %s \n", lcs);
}


int main (int argc , char * argv [])
{
    int row = 5;
    int column = 6;
    int A[row][column];
    int MAP[5][6] = {
        {1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {0, 1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 1},
    };
    
    task1(row, column, A, MAP);
    print(row, column, A);
    
    
    char X[] = "GEEKMINDS";
    char Y[] = "GEEKBRAINS";
    int m = strlen(X);
    int n = strlen(Y);
    lcs(X, Y, m, n);
    
    return 0;
}

