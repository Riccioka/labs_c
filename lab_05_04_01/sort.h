#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include "struct.h"

int bad_size(FILE *fp);

void print_student(t_student *stud);

void print_students(FILE *fin);

int student_cmp(t_student *l, t_student *r);

int sort(char *args);

#endif // SORT_H
