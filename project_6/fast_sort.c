#include <stdio.h>

#define NMAX 10

// Функция для обмена значениями двух элементов
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Рекурсивная быстрая сортировка
void qsortRecursive(int *mas, int size) {
    if (size < 2) return; // Если размер меньше 2, массив уже отсортирован

    int i = 0;
    int j = size - 1;
    int mid = mas[size / 2];

    do {
        while (mas[i] < mid) {
            i++;
        }
        while (mas[j] > mid) {
            j--;
        }

        if (i <= j) {
            swap(&mas[i], &mas[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        qsortRecursive(&mas[i], size - i);
    }
}

// Функция преобразования в кучу поддерева с корнем в i-м узле
void heapify(int arr[], int n, int i) {
    int largest = i;   // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый ребенок
    int r = 2 * i + 2; // правый ребенок

    // Если левый ребенок больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый ребенок больше, чем наибольший элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если наибольший элемент не корень
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // Рекурсивно преобразуем в кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция пирамидальной сортировки
void heapSort(int arr[], int n) {
    // Построение max-кучи
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        swap(&arr[0], &arr[i]);
        // Преобразуем уменьшенную кучу
        heapify(arr, i, 0);
    }
}

// Функция для вывода массива
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[NMAX];
    int arr_qsort[NMAX];
    int n = NMAX; // Жестко заданный размер

    // Чтение массива
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("n/a\n");
            return 1; // Обработка ошибки ввода
        }
    }

    // Копирование массива для qsort
    for (int i = 0; i < n; i++) {
        arr_qsort[i] = arr[i];
    }

    // Сортировка и вывод
    qsortRecursive(arr_qsort, n);
    heapSort(arr, n);

    printArray(arr_qsort, n); // Вывод после Quicksort
    printArray(arr, n);       // Вывод после Heapsort

    return 0;
}
