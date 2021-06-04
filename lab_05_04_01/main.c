#include <stdio.h>
#include <string.h>
#include <assert.h>

#define ERR_IO 1
#define ERR 3
#define ERR_PARAM 53
#define OK 0

#define N_MAX 10
#define ERR_MEM -4
#define ERR_FILE 5
#define EMPTY_FILE 6

#define MAX_STR_LEN 128
#define INT_SIZE 4
#define SURNAME 25
#define NAME 10

typedef struct
{
    char surname[SURNAME];
    char name[NAME];
    unsigned int a[INT_SIZE];
} t_student;

int file_size(FILE *f, int *k)
{
    int rc = OK, size;
    if (fseek(f, 0, SEEK_END) == 0)
    {
        size = ftell(f);
        *k = size / sizeof(t_student);
        if (size % sizeof(t_student) != 0)
            rc = ERR_IO;
        else if (*k > N_MAX)
        {
            *k = N_MAX;
            rc = ERR_MEM;
        }
        if (fseek(f, 0, SEEK_SET) != 0)
            rc = ERR;
    }
    else
        rc = ERR;
    return rc;
}

void print_a(const unsigned int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%u ", a[i]);
}

void print_struct(const t_student student)
{
    printf("%s\n", student.surname);
    printf("%s\n", student.name);
    print_a(student.a, INT_SIZE);
    printf("\n\n");
}

int print_bin_file(FILE *f)
{
    int k = 0, rc = OK;
    t_student student;
    if (fseek(f, 0, SEEK_SET) == OK)
    {
        rc = file_size(f, &k);
        if (rc == OK)
            for (int i = 0; i < k; ++i)
            {
                fread(&student, sizeof(t_student), 1, f);
                print_struct(student);
            }
    }
    else
        rc = ERR;
    return rc;
}

int check_file(FILE *f)
{
    int k = 0, rc = OK;
    rc = file_size(f, &k);
    if (rc == OK)
    {
        if (fseek(f, 0, SEEK_SET) == 0)
        {
            if (k == 0)
                return EMPTY_FILE;
        }
        else
            return ERR;
    }
    else
        return ERR;
    return rc;
}

int get_student_by_pos(FILE *f, int pos, t_student *get_student)
{
    int rc = OK;
    if (fseek(f, pos * sizeof(t_student), SEEK_SET) == 0)
    {
        if (fread(get_student, sizeof(t_student), 1, f) != 1)
            rc = ERR_IO;
    }
    else
        rc = ERR;
    return rc;
}

int put_student_by_pos(FILE *f, int pos, t_student put_student)
{
    int rc = OK;
    if (fseek(f, pos * sizeof(t_student), SEEK_SET) == 0)
    {
        if (fwrite(&put_student, sizeof(t_student), 1, f) != 1)
            rc = ERR_IO;
    }
    else
        rc = ERR;
    return rc;
}

int sort(FILE *f)
{
    int k = 0, rc = OK;
    t_student f_student, s_student;
    rc = file_size(f, &k);
    if (rc == OK)
    {
        for (int i = 0; i < k - 1; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                if (get_student_by_pos(f, i, &f_student) != OK)
                    return ERR;
                if (get_student_by_pos(f, j, &s_student) != OK)
                    return ERR;
                if (strcmp(f_student.surname, s_student.surname) > 0)
                {
                    if (put_student_by_pos(f, i, s_student) != OK)
                        return ERR;
                    if (put_student_by_pos(f, j, f_student) != OK)
                        return ERR;
                }
                else
                {
                    if (strcmp(f_student.surname, s_student.surname) == 0)
                    {
                        if (strcmp(f_student.name, s_student.name) > 0)
                        {
                            if (put_student_by_pos(f, i, s_student) != OK)
                                return ERR;
                            if (put_student_by_pos(f, j, f_student) != OK)
                                return ERR;
                        }
                    }
                }
            }
        }
    }
    return rc;
}

int read_stud_info_text(FILE *f, t_student *student)
{
    char buf[8];
    int len;
    if (!fgets(student->surname, sizeof(student->surname), f))
        return ERR_IO;
    len = strlen(student->surname);
    if (student->surname[len - 1] == '\n')
        student->surname[len - 1] = 0;
    if (!fgets(student->name, sizeof(student->name), f))
        return ERR_IO;
    len = strlen(student->name);
    if (student->name[len - 1] == '\n')
        student->name[len - 1] = 0;
    if (fscanf(f, "%u%u%u%u", &student->a[0], &student->a[1],
        &student->a[2], &student->a[3]) != 4)
        return ERR_IO;
    fgets(buf, sizeof(buf), f);
    return OK;
}

int read_in_array_text(FILE *f, t_student *arr, int *n)
{
    t_student cur;
    int k = 0;
    int rc = OK;
    while (rc == OK)
    {
        rc = read_stud_info_text(f, &cur);
        if (rc == OK)
        {
            if (k < N_MAX)
            {
                arr[k] = cur;
                k++;
            }
            else
                rc = ERR_MEM;
        }
        *n = k;
    }
    if (rc != ERR_MEM)
        rc = OK;
    return rc;
}

void del_stud(t_student *arr, float *mas_avr, int *n, float s_sr)
{
    int h = 0, i = 0;
    int n1 = *n;
    while (h < n1)
    {
        if (mas_avr[h] < s_sr)
        {
            for (int j = i; j < *n - 1; j++)
                arr[j] = arr[j + 1];
            *n -= 1;
        }
        else
            i++;
        h++;
    }
}

float average_calc(t_student *arr, int n, float *mas_avr)
{
    assert(n > 0);
    float s = 0;
    float s_sr = 0;
    for (int i = 0; i < n; i++)
    {
        s = 0;
        for (int j = 0; j < INT_SIZE; j++)
            s += arr[i].a[j];
        mas_avr[i] = s / INT_SIZE;
        s_sr += mas_avr[i];
    }
    s_sr = s_sr / n;
    return s_sr;
}

void print_st_info_file(FILE *f, t_student *student)
{
    fprintf(f, "%s\n", student->surname);
    fprintf(f, "%s\n", student->name);
    fprintf(f, "%u %u %u %u\n", student->a[0], student->a[1],
        student->a[2], student->a[3]);
}

void print_st_array_file(FILE *f, t_student *arr, int n)
{
    for (int i = 0; i < n; i++)
        print_st_info_file(f, &arr[i]);
}

int main(int argc, char *argv[])
{
    t_student arr[N_MAX];
    float mas_avr[N_MAX];
    int n = 0;
    float s_sr;
    int rc = OK;
    FILE *f;
    if (argc != 3)
        rc = ERR_PARAM;
    else if (strcmp(argv[1], "dt") == 0)
    {
        f = fopen(argv[2], "rt");
        if (f == NULL)
            rc = ERR_FILE;
        else
        {
            rc = read_in_array_text(f, arr, &n);
            if (n == 0)
                rc = EMPTY_FILE;
            if (rc == OK)
            {
                s_sr = average_calc(arr, n, mas_avr);
                del_stud(arr, mas_avr, &n, s_sr);
                fclose(f);
                f = fopen(argv[2], "wt");
                print_st_array_file(f, arr, n);
            }
            fclose(f);
        }
    }
    else if (strcmp(argv[1], "sb") == 0)
    {
        f = fopen(argv[2], "r + b");
        if (f == NULL)
            rc = ERR_FILE;
        else
        {
            rc = check_file(f);
            if (rc != OK)
                fclose(f);
            else
            {
                rc = sort(f);
                if (rc == OK)
                    print_bin_file(f);
                fclose(f);
            }
        }
    }
    else
        rc = ERR_PARAM;
    return rc;
}
