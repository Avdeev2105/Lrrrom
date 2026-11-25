#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
void d_st(int side, char sy) {
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            if (i == 0 || i == side - 1 || j == 0 || j == 2 * i) {
                printf("%c", sy);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
float a_se(float side) {
    return (side * side) / 2;
}
int check(double x, double y, int side) {
    if (side <= 0) return 0;
    if (y < 0) return 0;
    if (y > side - 1) return 0;
    double center = side - 1;
    double versh = y;
    if (x >= center - versh - 0.5 && x <= center + versh + 0.5)
        return 1;
    return 0;
}
void p_d() {
    printf(" Треугольник — фигура, состоящая из трёх точек вершин, не лежащих на одной прямой, которые соединены тремя сторонами.\n");
}
int g_side() {
    int side;
    printf("Введите высоту треугольника: ");
    scanf("%d", &side);
    while (getchar() != '\n');
    return side;
}

char g_sy() {
    char sy;
    printf("Введите символ которым рисовать: ");
    scanf(" %c", &sy);
    while (getchar() != '\n');
    return sy;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int choice;
    int side;
    char sy;
    side = g_side();
    sy = g_sy();
    do {
        printf("\n--- Меню операций для фигуры ---\n");
        printf("1. Рассчитать площадь\n");
        printf("2. Вывести определение фигуры\n");
        printf("3. Нарисовать фигуру \n");
        printf("4. Проверка принадлежности точки\n");
        printf("0. Выход\n");
        printf("Выберите операцию: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Площадь треугольника со стороной %d равна %.2f см(в кв)\n", side, a_se((float)side));
            break;
        case 2:
            p_d();
            break;
        case 3:
            printf("\nТреугольник:\n");
            d_st(side, sy);
            break;
        case 4:
            double x, y;
            printf("Введите значение переменной x :");
            scanf("%lf", &x);
            printf("Введите значение переменной y :");
            scanf("%lf", &y);
            if (check(x, y, side)) {
                printf("Точка (%.2f, %.2f) принадлежит фигуре.\n", x, y);
            }
            else {
                printf("Точка (%.2f, %.2f) не принадлежит фигуре.\n", x, y);
            }
            break;

        case 0:
            printf("Программа завершена.\n");
            return 0;
        default:
            printf("\n$$$$$ Неправильный ввод $$$$$\n");
        }
    } while (choice != 0);
    return 0;
}