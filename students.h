#pragma once

struct student {
    char fam[20];
    int birth;
    int entry;
    int fiz;
    int math;
    int inf;
};

extern student* students_data;   
extern int current_count;
extern int capacity;

extern void enter();
extern void enter_from_file();
extern void print();
extern int read();
extern void print_otlichniki();
extern int sort();
extern void sort_fam();
extern void sort_birth();
extern void sort_entry();
extern void sort_fiz();
extern void sort_math();
extern void sort_inf();