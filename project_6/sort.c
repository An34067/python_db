#include <stdio.h>
#define NMAX 10

int input(int *a);
void sort(int *a);
void output(int *a);

int main() {
    int data[NMAX];

    if (!input(data)) {
        printf("n/a\n");
        return 1;
    }
    sort(data);
    output(data);

    return 0;
}

int input(int *a) {
    // Функция больше не принимает размер массива (int *n)
    // Теперь она всегда читает NMAX элементов

    for (int i = 0; i < NMAX; i++) {  // Цикл всегда выполняется NMAX (10) раз
        if (scanf("%d", &a[i]) != 1) {
            return 0;
        }
    }
    return 1;
}

void sort(int *a) {
    // Функция больше не принимает размер массива (int n)
    // Теперь она всегда сортирует массив размером NMAX

    for (int i = NMAX - 1; i >= 1; i--) {  // Используется NMAX
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                int f = a[j];
                a[j] = a[j + 1];
                a[j + 1] = f;
            }
        }
    }
}

void output(int *a) {
    // Функция больше не принимает размер массива (int n)
    // Теперь она всегда выводит массив размером NMAX

    for (int i = 0; i < NMAX; i++) {  // Используется NMAX
        printf("%d", a[i]);
        if (i < NMAX - 1) {  // Используется NMAX и правильное расположение скобок
            printf(" ");
        }
    }
    printf("\n");
}