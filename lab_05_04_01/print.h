#ifndef PRINT_H
#define PRINT_H


typedef struct s_student
{
    char surname[25];
    char name[10];
    unsigned int a[4];
}				t_student;

int sort(char **args);

int print(char **args);

int extract_cmd(const char *arg);

int del(char **args);

#endif // PRINT_H
