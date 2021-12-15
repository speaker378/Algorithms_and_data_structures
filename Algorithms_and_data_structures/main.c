//
//  main.c
//  Algorithms_and_data_structures
//
//  Created by Сергей Черных on 15.12.2021.
//

#include <stdio.h>
#include <math.h>

void menu(void);
void solution1(void);
void solution2(void);
void solution3(void);
void solution4(void);
void solution5(void);

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
            case 4:
                solution4();
                break;
            case  5:
                solution5();
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


void menu() {
    printf("\n");
    printf("******************\n");
    printf("  1 - Задача 1 \n");
    printf("  2 - Задача 2 \n");
    printf("  3 - Задача 3 \n");
    printf("  4 - Задача 4 \n");
    printf("  5 - Задача 5 \n");
    printf("  0 - Выход \n");
    printf("******************\n");
}

// 1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах.

void solution1() {
    double bmi, height, weight;
    printf("Введите свой рост в см\n");
    scanf("%lf", &height);
    printf("Введите свой вес в кг\n");
    scanf("%lf", &weight);
    bmi = weight / (height / 100 * height / 100);
    printf("Индекс массы тела: %lf \n", bmi);
}

// 2. Найти максимальное из четырех чисел. Массивы не использовать.

void solution2() {
    double a, b, c, d, max;
    printf("Введите первое число\n");
    scanf("%lf", &a);
    printf("Введите второе число\n");
    scanf("%lf", &b);
    printf("Введите третье число\n");
    scanf("%lf", &c);
    printf("Введите четвертое число\n");
    scanf("%lf", &d);
    max = a;
    
    if (max < b) {
        max = b;
    }
    if (max < c) {
        max = c;
    }
    if (max < d) {
        max = d;
    }
    printf("Наибольшее число %lf \n", max);
}

// 3. Написать программу обмена значениями двух целочисленных переменных:
// a. с использованием третьей переменной;
// b. *без использования третьей переменной.

void solution3() {
    int a, b, temp;
    a = 7;
    b = 11;
    printf("a = %i, b = %i \n", a, b);
    temp = a;
    a = b;
    b = temp;
    printf("a = %i, b = %i \n", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("a = %i, b = %i \n", a, b);
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    printf("a = %i, b = %i \n", a, b);
}

// 4. Написать программу нахождения корней заданного квадратного уравнения.

void solution4() {
    double a, b, c, d, x1, x2;
    printf("Введите коэффициент a \n");
    scanf("%lf", &a);
    printf("Введите коэффициент b \n");
    scanf("%lf", &b);
    printf("Введите коэффициент c \n");
    scanf("%lf", &c);
    d = (b * b) - (4 * a * c);
    if (d < 0) {
        printf("Корней нет \n");
    } else if (d == 0) {
        x1 = -b / (2 * a);
        printf("Один корень: %lf \n", x1);
    } else if (d > 0) {
        double sd = sqrt(d);
        x1 = (-b + sd) / (2 * a);
        x2 = (-b - sd) / (2 * a);
        printf("Корней два: \n x1 = %lf \n x2 = %lf \n", x1, x2);
    }
}

// 5. С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.

void solution5() {
    int n;
    printf("Введите номер месяца n \n");
    scanf("%i", &n);
    
    if (n == 1 || n == 2 || n == 12) {
        printf("Зима");
    } else if (n == 3 || n == 4 || n == 5) {
        printf("Весна");
    } else if (n == 6 || n == 7 || n == 8) {
        printf("Лето");
    } else if (n == 9 || n == 10 || n == 11) {
        printf("Осень");
    } else {
        printf("Такого месяца нет");
    }
    
}
