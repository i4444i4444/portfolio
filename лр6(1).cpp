//В одномерном массиве, состоящем из n целых элементов, вычислить:
//– произведение элементов массива с четными номерами;
//– сумму элементов массива, расположенных между первым и последним
//нулевыми элементами.

#include<stdio.h> 
#include<locale.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_ALL, "rus");
	int n, i;

	printf("Введите количество элементов массива (<100)\n");
	scanf_s("%d", &n);

	int* a = (int*)malloc(n * sizeof(int));
	if (a == NULL) {
		printf("Ошибка выделения памяти.\n");
		return 1;
	}

	printf("Введите %d элементов массива:\n", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a + i);
	}

	int* p = (int*)malloc(sizeof(int));
	*p = 1;
	int* has_even_elements = (int*)malloc(sizeof(int));
	*has_even_elements = 0;

	for (i = 0; i < n; i += 2) {
		*p *= *(a + i);
		*has_even_elements = 1;
	}

	if (*has_even_elements) {
		printf("\nПроизведение элементов с четными номерами: %d\n", *product);
	}
	else {
		printf("Нет элементов с четными номерами.\n");
	}

	int* first = (int*)malloc(sizeof(int));
	int* last = (int*)malloc(sizeof(int));
	*first = -1;
	*last = -1;

	for (i = 0; i < n; i++) {
		if (*(a + i) == 0) {
			&first = i;
			break;
		}
	}

	for (i = n - 1; i >= 0; i--) {
		if (*(a + i) == 0) {
			&last = i;
			break;
		}
	}

	if (*first == -1 || *last == -1) {
		printf("В массиве нет нулевых элементов.\n");
	}
	else if (*first == *last) {
		printf("В массиве только один нулевой элемент.\n");
	}
	else if (*last - *first <= 1) {
		printf("Между первым и последним нулевыми элементами нет других элементов.\n");
	}
	else {
		int* sum = (int*)malloc(sizeof(int));
		*sum = 0;
		printf("Элементы между нулевыми элементами [%d] и [%d]: ", *first, *last);

		for (i = *first + 1; i < *last; i++) {
			printf("%d ", *(a + i));     
			*sum += *(a + i);          
		}

		printf("\nСумма элементов между первым и последним нулевыми элементами: %d\n", *sum);

		free(sum);
	}

	free(a);
	free(p);
	free(has_even_elements);
	free(first);
	free(last);

	return 0;
}