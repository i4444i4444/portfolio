//С клавиатуры задать массив из 8 элементов, где первые три числа 
//положительных.Поменять местами первый элемент массива и первый отрицательный 
//элемент массива.Вывести на экран номера отрицательных чисел массива.

#include<stdio.h>
#include<conio.h>
#include<locale.h>
int main()
{
	setlocale(0, "rus");
	int a[8], i = 0, n=0;

		printf("Введите 8 чисел(первые три должны быть положительными)\n");
		for (i = 0; i < 3; i++)
		{
			printf("Число %d: ", i + 1);
			scanf_s("%d", &a[i]);
			if (a[i] <= 0) {
				printf("Ошибка! Первые три элемента должны быть положительными. Повторите ввод.\n");
				scanf_s("%d", &a[i]);
			}
		}

		for (i = 3; i < 8; i++) {
			printf("Элемент %d: ", i + 1);
			scanf_s("%d", &a[i]);
		}

		printf("\nИсходный массив: ");
		for (i = 0; i < 8; i++) {
			printf("%d", a[i]);
		}

		int FirstNegative = -1;

		for (i = 0; i < 8; i++) {
			if (a[i] < 0) {
				FirstNegative = i;
				break;
			}
		}

		if (FirstNegative != -1) {
			int tmp = a[0];
			a[0] = a[FirstNegative];
			a[FirstNegative] = tmp;
			printf("Поменяли местами элементы с индексами 0 и %d\n", FirstNegative);
		}
		else {
			printf("Отрицательных элементов в массиве нет\n");
		}
        
		printf("Измененный массив: ");
		for (i = 0; i < 8; i++) {
			printf("%d", a[i]);
		}

		printf("Номера отрицательных элементов: ");
		int count = 0;  

		for (i = 0; i < 8; i++) {
			if (a[i] < 0) {
				printf("%d", i + 1);
				count++;  
			}
		}

		if (count == 0) {  
			printf("Отрицательных элементов нет");
		}

	_getch();
	return 0;
}