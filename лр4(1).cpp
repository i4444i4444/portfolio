//Дан массив А размером n, не содержащий нулевых элементов. 
//Необходимо получить массив А, в котором вначале идут положительные 
//элементы, а затем отрицательные.Дополнительные массивы не использовать.

#include<stdio.h>
#include<conio.h>
#include<locale.h>
int main()
{
	setlocale(0, "rus");
	int A[100], i=0, n;
	 
	do {
		printf("Введите размер массива (1-100): ");
		scanf_s("%d", &n);

		if (n <= 0 || n > 100) {
			printf("Неверный размер массива. Допустимый диапазон: 1-100.\n");
		}
	} while (n <= 0 || n > 100);

	for (i = 0; i < n; i++)
	{
		printf("Число %d: ", i + 1);
		scanf_s("%d", &A[i]);

		while (A[i] == 0)
		{
			printf("Ошибка. Элемент не должен быть равен нулю.\n");
			printf("Введите число %d снова: ", i + 1);
			scanf_s("%d", &A[i]);
		}
		
	}
	
	printf("\nИсходный массив: ");
	for (i = 0; i < n; i++)
		printf("%d", A[i]);
	printf("\n");

	int positive = 0, tmp;
	for (i = 0; i < n; i++)
	{
		if (A[i]>0)
		{
			if (i != positive)
			{
				tmp = A[i];
				A[i] = A[positive];
				A[positive] = tmp;
			}
			positive++;
		}
	}

	printf("Отсортированный массив (сначала положительные, потом отрицательные):\n");
	for (i = 0; i < n; i++)
		printf("%d", A[i]);
	printf("\n");

	_getch();
	return 0;
}