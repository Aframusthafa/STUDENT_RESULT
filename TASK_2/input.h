#ifndef INPUT_H
#define INPUT_H
#include<stdio.h>

struct Student{
    char id[9];
    char name[20];
    int minor[5];
    int major[5];
};
void output();

extern int count;
extern float total_percentage;
extern float highest;
extern float lowest;
extern int count_O,count_AP,count_A,count_BP,count_B,count_C,count_D,count_F;

extern struct Student student;
extern FILE *out;
extern int count;
extern char stored_ids[100][9];
extern int stored_count;

#endif