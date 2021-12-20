//
//  main.c
//  Algorithms_and_data_structures
//
//  Created by Сергей Черных on 15.12.2021.
//

#include <stdio.h>
#include <math.h>
typedef enum { false, true } bool;

void menu(void) {
    printf("\n");
    printf("******************\n");
    printf("  1 - Задача 1 \n");
    printf("  2 - Задача 2 \n");
    printf("  3 - Задача 3 \n");
    printf("  0 - Выход \n");
    printf("******************\n");
}

// 1. Реализовать функцию перевода из десятичной системы в двоичную, используя рекурсию.
int decToBinInteger(int dec) {
    if (dec == 0)
        return 0;
    else
        return (dec % 2 + 10 * decToBinInteger(dec / 2));
}

double decToBinFraction(double dec) {
    static long count = 1;
    count *= 10;
    if (dec < 0.0001) {
        count = 1;
        return 0;
    }
    else {
        double d = dec * 2;
        double i = (int) d;
        double f = d - i;
        return (i / count + decToBinFraction(f));
    }
}

void solution1(void) {
    int integer, resultInteger;
    double num, fraction, resultFraction, result;
    bool sign;
    printf("Введите число:");
    scanf("%lf", &num);
    
    sign = (num < 0) ? true : false;
    num = fabs(num);
    
    integer = (int) num;
    resultInteger = decToBinInteger(num);
    fraction = num - integer;
    resultFraction = decToBinFraction(fraction);
    result = resultInteger + resultFraction;
    printf("%lf", (sign) ? -result : result);
}

// 2. Реализовать функцию возведения числа a в степень b:
//      a. без рекурсии;
//      b. рекурсивно;
//      c. *рекурсивно, используя свойство четности степени.
int power(int x, int n)
 {
     int a = 1;
     while(n) {
         if(n % 2) {
             a *= x;
             n -= 1;
         }
         else{
             x *= x;
             n /= 2;
         }
     }
     return a;
 }

int powRecurs(int x, int n) {
    if (n == 1)
        return x;
    else
        return (x * powRecurs(x, n - 1));
}

int powRecursFast(int x, int n) {
    if (n == 1)
        return x;
    if (n % 2)
        return (x * powRecursFast(x, n - 1));
    else {
        int c = powRecursFast(x, n / 2);
        return c * c;
    }
}

void solution2(void) {
    int x, n, m, result;
    printf("Введите число:");
    scanf("%i", &x);
    printf("Введите степень:");
    scanf("%i", &n);
    printf("Выбор метода: 1, 2, 3 \n");
    scanf("%i", &m);
    switch (m) {
        case 1:
            result = power(x, n);
            break;
        case 2:
            result = powRecurs(x, n);
            break;
        case 3:
            result = powRecursFast(x, n);
            break;
        default:
            result = 0;
            break;
    }
    printf("%i", result);
}


// 3. **Исполнитель Калькулятор преобразует целое число, записанное на экране. У исполнителя две команды, каждой команде присвоен номер:
//      Прибавь 1
//      Умножь на 2
// Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза.
// Сколько существует программ, которые число 3 преобразуют в число 20?
int calc(int start, int stop, int add, int multiply) {
    if (start == stop) {
        return 1;
    } else if (start > stop) {
        return 0;
    } else {
        return calc(start + add, stop, add, multiply) + calc(start * multiply, stop, add, multiply);
    }
}

void solution3(void) {
    int result = calc(3, 20, 1, 2);
    printf("Всего существует %i программ, которые число 3 преобразуют в число 20 \n", result);
}


int main(int argc, const char * argv[]) {
    int select = 0;
    do {
        menu();
        scanf("%i", &select);
        switch (select) {
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
                printf("Пока! \n");
                break;
            default:
                printf("Ошибка выбора! \n");
        }
    } while (select != 0);
    return 0;
}
