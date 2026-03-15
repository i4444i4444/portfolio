//Найти в матрице первый столбец, все элементы которого положительны.
//Знаки элементов предыдущего столбца изменить на противоположные

#include<stdio.h>
#include<conio.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "rus");
	int i, j, rows, cols;
	float b[20][20];
	do
	{
		printf("Введите количество строк (<20)\n");
		scanf_s("%d", &rows);
	} while (rows >= 20 || rows <= 0);

	do
	{
		printf("Введите количество столбцов (<20)\n");
		scanf_s("%d", &cols);
	} while (cols >= 20 || cols <= 0);

	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
		{
			printf("Введите элемент [%d, %d]\n", i + 1, j + 1);
			scanf_s("%f", &b[i][j]);
		}

	printf("Исходная матрица:\n");
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			printf("%.2f", b[i][j]);
		printf("\n");
	}

	int positive = -1;
	j = 0;
	int found = 0;

	do 
	{
		int all_positive = 1;
		for (i = 0; i < rows; i++)
		{
			if (b[i][j] <= 0)
			{
				all_positive = 0;
				break;
			}
		}
		if (all_positive)
		{
			positive = j;
			found = 1;
		}
		j++;

	} while (j < cols && !found);

	if (found)
	{
		printf("Первый столбец, все элементы которого положительны: [%d]\n", positive + 1);

		if (positive > 0)
		{
			for (i = 0; i < rows; i++)
			{
				b[i][positive - 1] = -b[i][positive - 1];
			}

			printf("Матрица после изменения знаков:\n");
			for (i = 0; i < rows; i++)
			{
				for (j = 0; j < cols; j++)
					printf("%.2f", b[i][j]);
				printf("\n");
			}
		}
	}

	else {
		printf("Столбца с положительными элементами не найдено\n");
	}
	
	_getch();
	return 0;

}