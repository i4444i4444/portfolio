#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

void BubbleSort(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        bool sorted = true;
        for (int j = 1; j < n - i; j++) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                sorted = false;
            }
        }
        if (sorted) break;
    }
}

void insertSort(int* a, int n) {
    for (int i = 1; i < n; i++) {
        int x = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

void MinSort(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_i = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min_i])
                min_i = j;
        swap(a[i], a[min_i]);
    }
}

void SortShell(int* a, int n) {
    int gap;        // шаг сортировки
    int sorted;     // флаг перестановок

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        do
        {
            sorted = 0;

            for (int i = 0, j = gap; j < n; i++, j++)
            {
                if (a[i] > a[j])
                {
                    swap(a[i], a[j]);
                    sorted = 1;
                }
            }

        } while (sorted);
    }
}

void QuickSort(int* a, int left, int right)
{
    int i = left;
    int j = right;
    int pivot = a[(left + right) / 2]; // опорный элемент

    do
    {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }

    } while (i <= j);

    if (left < j)
        QuickSort(a, left, j);

    if (i < right)
        QuickSort(a, i, right);
}

int main() {
    setlocale(LC_ALL, "rus");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* a = new int[n];
    int* original = new int[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100000;
        original[i] = a[i];
    }

    cout << "\nПервые 10 элементов массива: \n";
    for (int i = 0; i < 10 && i < n; i++)
        cout << a[i] << " ";
    cout << "\n";

    int choice;
    do {
        cout << "\nМеню сортировки: \n";
        cout << "1. Сортировка пузырьком\n";
        cout << "2. Сортировка вставками\n";
        cout << "3. Сортировка методом выбора\n";
        cout << "4. Сортировка методом Шелла\n";
        cout << "5. Сортировка методом Хоара (быстрая сортировка)\n";
        cout << "6. Вернуть исходный массив\n";
        cout << "7. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        clock_t start, end;

        switch (choice) {
        case 1: 
            start = clock();
            BubbleSort(a, n);
            end = clock();
            break;

        case 2:
            start = clock();
            insertSort(a, n);
            end = clock();
            break;

        case 3:
            start = clock();
            MinSort(a, n);
            end = clock();
            break;

        case 4:
            start = clock();
            SortShell(a, n);
            end = clock();
            break;

        case 5:
            start = clock();
            QuickSort(a, 0, n - 1);
            end = clock();
            break;

        case 6:
            for (int i = 0; i < n; i++)
                a[i] = original[i];

            cout << "\nМассив восстановлен.\n";
            cout << "Первые 10 элементов:\n";
            for (int i = 0; i < 10 && i < n; i++)
                cout << a[i] << " ";
            cout << "\n";
            continue;

        case 7:
            delete[] a;
            delete[] original;
            return 0;

        defaulf:
            cout << "Неверный выбор.";
                continue;
        }

        double time = double(end - start) / CLOCKS_PER_SEC;

        cout << "\n Время сортировки: " << time << "сек\n";

        cout << "Первые 10 элементов после сортировки:\n";
        for (int i = 0; i < 10 && i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    } while (choice != 7);

    delete[] a;
    return 0;
}