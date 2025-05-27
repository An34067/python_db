#include <stdio.h>

#define MAX_SIZE 10

int read_array(int *arr, int *n);
void cycle_shift(int *arr, int n, int c);
void print_array(int *arr, int n);

int main() {
    int arr[MAX_SIZE];
    int n, c;

    if (read_array(arr, &n)) {
        printf("n/a\n");
        return 1;
    }

    if (scanf("%d", &c) != 1) {
        printf("n/a\n");
        return 1;
    }

    cycle_shift(arr, n, c);
    print_array(arr, n);

    return 0;
}

// Функция для чтения массива из стандартного ввода
int read_array(int *arr, int *n) {
    if (scanf("%d", n) != 1 || *n <= 0 || *n > MAX_SIZE) {
        return 1;
    }
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return 1;
        }
    }
    return 0;
}

// Функция для циклического сдвига массива
void cycle_shift(int *arr, int n, int c) {
    // Нормализуем c, чтобы избежать многократных сдвигов
    c = c % n;
    if (c < 0) {
        c = c + n;  // Приводим к положительному сдвигу вправо
    }

    // Выполняем сдвиг
    for (int i = 0; i < c; i++) {
        // Сдвиг влево
        int temp = arr[0];
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = temp;
    }
}

// Функция для вывода массива в стандартный вывод
void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}