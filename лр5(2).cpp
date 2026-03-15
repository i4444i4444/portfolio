//Дан двумерный массив W размером 6 × 6, заполненный случайными 
//числами.Для каждой строки массива найти максимальный элемент.Найти
//максимальные элементы диагонали.Найти сумму всех максимальных 
//элементов.Вывести значения суммы на экран.

#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include <time.h>
#include<stdlib.h>

#define SIZE 6

int main()
{
	setlocale(LC_ALL, "rus");
	int W[SIZE][SIZE];
	int i, j;

	srand(time_t(NULL));

	printf("Массив W:\n");

	for (i = 0; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++) {
				W[i][j] = -6 + rand() % 20;  
				printf("%4d", W[i][j]);
			}
			printf("\n");
	};

	int max[SIZE];
	for (i = 0; i < 6; i++) {
		max[i] = W[i][0];
		for (j = 1; j < 6; j++)
		{
			if (W[i][j] > max[i]) {
				max[i] = W[i][j];
			}
		}
		printf("Максимальный элемент %d строки = %d\n", i + 1, max[i]);
	};

	int max_diagonal = W[0][0];
	for (i = 1; i < SIZE; i++) {
		if (W[i][i] > max_diagonal) {
			max_diagonal = W[i][i];
		}
	}
	printf("Максимальный элемент главной диагонали: %d\n", max_diagonal);

	int sum = 0;
	for (i = 0; i < SIZE; i++) {
		sum += max[i];
	}
	sum += max_diagonal;
	printf("Сумма всех максимальных элементов: %d\n", sum);

	_getch();
	return 0;
}