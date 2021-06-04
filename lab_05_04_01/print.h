#ifndef PRINT_H
#define PRINT_H


typedef struct s_student
{
    char surname[26];
    char name[11];
    unsigned int a[4];
}				t_student;

int sort(char **args);

int print(char *file_src, char *file_dst, char *substr);

int extract_cmd(const char *arg);

int del(char **args);

#endif // PRINT_H
