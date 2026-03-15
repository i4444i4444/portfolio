#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include "students.h"

using namespace std;

bool is_digits(const char* s)
{
    for (int i = 0; s[i] != '\0'; i++)
        if (!isdigit((unsigned char)s[i]))
            return false;
    return true;
}

student* students_data = nullptr;
int current_count = 0;
int capacity = 0;

static void ensure_capacity()
{
    if (current_count < capacity) return;

    int new_capacity = (capacity == 0 ? 4 : capacity * 2);

    student* new_data = new student[new_capacity];

    int i;
    for (i = 0; i < current_count; i++)
        new_data[i] = students_data[i];

    delete[] students_data;
    students_data = new_data;
    capacity = new_capacity;
}

extern void enter()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    cout << "\nВвод данных о студенте:\n";

    student new_student;

    cout << "Фамилия: ";
    cin >> new_student.fam;
    while (strlen(new_student.fam) == 0) {
        cout << "Ошибка! Фамилия не может быть пустой. Повторите ввод: ";
        cin >> new_student.fam;
    }

    cout << "Год рождения: ";
    cin >> new_student.birth;
    while (cin.fail() || new_student.birth < 1900) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка. Год рождения должен быть числом не меньше 1900. Повторите ввод: ";
        cin >> new_student.birth;
    }

    cout << "Год поступления: ";
    cin >> new_student.entry;
    while (cin.fail() || new_student.entry < 1900) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка. Год должен быть числом не меньше 1900. Повторите ввод: ";
        cin >> new_student.entry;
    }

    cout << "Оценка по физике: ";
    cin >> new_student.fiz;
    while (cin.fail() || new_student.fiz < 0 || new_student.fiz > 10) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка. Оценка должна быть числом от 0 до 10. Повторите ввод: ";
        cin >> new_student.fiz;
    }

    cout << "Оценка по высшей математике: ";
    cin >> new_student.math;
    while (cin.fail() || new_student.math < 0 || new_student.math > 10) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка. Оценка должна быть числом от 0 до 10. Повторите ввод: ";
        cin >> new_student.math;
    }

    cout << "Оценка по информатике: ";
    cin >> new_student.inf;
    while (cin.fail() || new_student.inf < 0 || new_student.inf > 10) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка. Оценка должна быть числом от 0 до 10. Повторите ввод: ";
        cin >> new_student.inf;
    }

    ensure_capacity();
    students_data[current_count] = new_student;
    current_count++;

    ofstream file("students.txt", ios::app);
    file << new_student.fam << " "
        << new_student.birth << " "
        << new_student.entry << " "
        << new_student.fiz << " "
        << new_student.math << " "
        << new_student.inf << "\n";
    file.close();

    cout << "\nСтудент добавлен и сохранён в файл.\n";
}

extern void enter_from_file()
{
    ifstream file("students.txt");

    if (!file)
    {
        cout << "Файл не найден.\n";
        return;
    }

    student new_student;

    while (file >> new_student.fam >> new_student.birth >> new_student.entry >> new_student.fiz >> new_student.math >> new_student.inf)
    {
        ensure_capacity();
        students_data[current_count] = new_student;
        current_count++;
    }

    file.close();
    cout << "Данные загружены из файла.\n";
}

extern void print()
{
    if (current_count == 0)
    {
        cout << "Нет данных.\n";
        return;
    }

    cout << "\n№  Фамилия       Рожд   Вступ  Физ  Мат  Инф\n";

    for (int i = 0; i < current_count; i++)
    {
        printf("%d  %-12s  %4d  %5d  %3d  %3d  %3d\n",
            i + 1,
            students_data[i].fam,
            students_data[i].birth,
            students_data[i].entry,
            students_data[i].fiz,
            students_data[i].math,
            students_data[i].inf);
    }

}

extern int read()
{
    if (current_count == 0)
    {
        cout << "Нет данных.\n";
        return 0;
    }

    int n;
    cout << "Введите номер студента: ";
    cin >> n;

    if (n < 1 || n > current_count)
    {
        cout << "Нет такого студента.\n";
        return 1;
    }

    n--;

    cout << "\nФамилия: " << students_data[n].fam << "\n";
    cout << "Год рождения: " << students_data[n].birth << "\n";
    cout << "Год поступления: " << students_data[n].entry << "\n";
    cout << "Физика: " << students_data[n].fiz << "\n";
    cout << "Математика: " << students_data[n].math << "\n";
    cout << "Информатика: " << students_data[n].inf << "\n\n";

    return 0;
}

extern void print_otlichniki()
{
    if (current_count == 0)
    {
        cout << "Нет данных.\n";
        return;
    }

    int found = 0;

    cout << "\nОтличники:\n";
    cout << "\n№  Фамилия       Рожд   Вступ  Физ  Мат  Инф\n";

    for (int i = 0; i < current_count; i++)
    {
        if (students_data[i].fiz >= 9 &&
            students_data[i].math >= 9 &&
            students_data[i].inf >= 9)
        {
            printf("%d  %-12s  %4d  %5d  %3d  %3d  %3d\n",
                i + 1,
                students_data[i].fam,
                students_data[i].birth,
                students_data[i].entry,
                students_data[i].fiz,
                students_data[i].math,
                students_data[i].inf);

            found = 1;
        }
    }

    if (!found)
        cout << "Отличников нет.\n";

}

void swap(student& a, student& b)
{
    student tmp = a;
    a = b;
    b = tmp;
}

extern void sort_fam()
{
    for (int i = 1; i < current_count; i++)
        for (int j = current_count - 1; j >= i; j--)
            if (strcmp(students_data[j - 1].fam, students_data[j].fam) > 0)
                swap(students_data[j - 1], students_data[j]);

    cout << "Отсортировано по фамилии.\n";
    print();
}

extern void sort_birth()
{
    for (int i = 1; i < current_count; i++)
        for (int j = current_count - 1; j >= i; j--)
            if (students_data[j - 1].birth > students_data[j].birth)
                swap(students_data[j - 1], students_data[j]);

    cout << "Отсортировано по году рождения.\n";
    print();
}

extern void sort_entry()
{
    for (int i = 1; i < current_count; i++)
        for (int j = current_count - 1; j >= i; j--)
            if (students_data[j - 1].entry > students_data[j].entry)
                swap(students_data[j - 1], students_data[j]);

    cout << "Отсортировано по году поступления.\n";
    print();
}

extern void sort_fiz()
{
    for (int i = 1; i < current_count; i++)
        for (int j = current_count - 1; j >= i; j--)
            if (students_data[j - 1].fiz < students_data[j].fiz)
                swap(students_data[j - 1], students_data[j]);

    cout << "Отсортировано по физике.\n";
    print();
}

extern void sort_math()
{
    for (int i = 1; i < current_count; i++)
        for (int j = current_count - 1; j >= i; j--)
            if (students_data[j - 1].math < students_data[j].math)
                swap(students_data[j - 1], students_data[j]);

    cout << "Отсортировано по математике.\n";
    print();
}

extern void sort_inf()
{
    for (int i = 1; i < current_count; i++)
        for (int j = current_count - 1; j >= i; j--)
            if (students_data[j - 1].inf < students_data[j].inf)
                swap(students_data[j - 1], students_data[j]);

    cout << "Отсортировано по информатике.\n";
    print();
}

extern int sort()
{
    if (current_count == 0)
    {
        cout << "Нет данных.\n";
        return 0;
    }

    int choice;

    do {
        cout << "\nСортировка:\n";
        cout << "1. По фамилии\n";
        cout << "2. По году рождения\n";
        cout << "3. По году поступления\n";
        cout << "4. По физике\n";
        cout << "5. По математике\n";
        cout << "6. По информатике\n";
        cout << "7. Назад\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice)
        {
        case 1: sort_fam(); break;
        case 2: sort_birth(); break;
        case 3: sort_entry(); break;
        case 4: sort_fiz(); break;
        case 5: sort_math(); break;
        case 6: sort_inf(); break;
        case 7: return 0;
        default: cout << "Неверный выбор.\n";
        }

    } while (choice != 7);

    return 0;
}
