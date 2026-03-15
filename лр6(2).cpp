// Дана целочисленная матрица размером 5 × 5. Определить, сколько в ней 
// пар соседних одинаковых элементов.Элементы считаются соседними, если их
// индексы в столбцах и / или в строках различаются не более чем на единицу.

#include<stdio.h> 
#include<locale.h>
#include<stdlib.h>

#define SIZE 5

int main()
{
	setlocale(LC_ALL, "rus");
	int a[SIZE][SIZE], i, j;
	int* ptr;

 printf("Введите элементы матрицы %dx%d:\n", SIZE, SIZE);
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf_s("%d", &a[i][j]);
        }
    }

    printf("\nМатрица:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    ptr = &a[0][0];
    int* pair = (int*)malloc(sizeof(int));
    *pair = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            int* p = ptr + i * SIZE + j;

            if (j < SIZE - 1) {
                int* right = p + 1;
                if (*p == *right) {
                    (*pair)++;
                    printf("Горизонтальная пара: %d и %d\n", *p, *right);
                }
            }

            if (i < SIZE - 1) {
                int* bottom = p + SIZE;
                if (*p == *bottom) {
                    (*pair)++;
                    printf("Вертикальная пара: %d и %d\n", *p, *bottom);
                }
            }

            if (i < SIZE - 1 && j < SIZE - 1) {
                int* diagonal_right = p + SIZE + 1;
                if (*ptr == *diagonal_right) {
                    (*pair)++;
                    printf("Диагональная пара (правый низ): %d и %d\n", *p, *diagonal_right);
                }
            }

            if (i < SIZE - 1 && j > 0) {
                int* diagonal_left = p + SIZE - 1;
                if (*ptr == *diagonal_left) {
                    (*pair)++;
                    printf("Диагональная пара (левый низ): %d и %d\n", *p, *diagonal_left);
                }
            }
        }
    }

    printf("\nОбщее количество пар: %d\n", *pair);

    free(pair);
    getchar();

    return 0;
}