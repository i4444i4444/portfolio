#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include "students.h"

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int choice;

    do {
        cout << "\nГлавное меню:\n";
        cout << "1. Ввод из файла\n";
        cout << "2. Ввод вручную\n";
        cout << "3. Вывод всех студентов\n";
        cout << "4. Поиск студента\n";
        cout << "5. Вывод отличников\n";
        cout << "6. Сортировка\n";
        cout << "7. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice)
        {
        case 1: enter_from_file(); break;
        case 2: enter(); break;
        case 3: print(); break;
        case 4: read(); break;
        case 5: print_otlichniki(); break;
        case 6: sort(); break;
        case 7: break;
        default: cout << "Неверный выбор.\n";
        }

    } while (choice != 7);

    return 0;
}
