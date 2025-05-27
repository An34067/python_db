/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

void input (int *buffer, int *length);
void output (int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers)

/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main()
{
    int buffer[NMAX];
    int length;
    int sum;
    int new_buffer [NMAX];
    int new_length;
    
    input(buffer, &length){
        if (length <= 0 || length > NMAX)
        {
            printf("n/a\n");
            return 1;
        }
        
    }
    
    sum = sum_numbers(buffer, length);
    if (sum == 0) {
        printf("n/a\n");
        return 1;
    }

    new_length = find_numbers(buffer, length, number, numbers);
    if (new_length == 0)
    {
        printf("n/a\n");
        return 1;
    }
    printf("%d ", sum);
    output(new_buffer, new_length);
    return 0;
}

void input (int *buffer, int *length){
    if(scanf("%d", n) != 1) return;
    for (int i = 0; i < *length; i++)
    {
        if(scanf("%d", &buffer[i]) != 1) return;
    }
    return 0;
}

void output (int *buffer, int length){
    for (int i = 0; i < length; i++)
    {
        printf("%d", &buffer[i]);
    }
    printf("\n");
}

/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length)
{
	int sum = 0;
	
	for (int i = 1; i < length; i++)
	{
		if (i % 2 != 0)
		{
			sum = sum + buffer[i];
		}
	}
	
	return sum;
}

/*int sum_numbers(int *buffer, int length) {
    int sum = 0; // Инициализация суммы

    for (int i = 0; i < length; i++) { // Проходим по всем элементам массива
        if (buffer[i] % 2 == 0 && buffer[i] != 0) { // Проверка на четность и не равенство нулю
            sum += buffer[i]; // Добавляем четный элемент к сумме
        }
    }
    return sum; // Возвращаем сумму
}*/


/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int* buffer, int length, int number, int* numbers)
{
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[count++] = buffer[i];
        }
    }
    return count;
}