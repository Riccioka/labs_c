#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student
{
    char Surname[25];
    char Name[10];
    int a[4];
};

int a(char *fname)
{
    FILE *file = fopen(fname, "rb");
    struct Student stud;

    if (!file)
        return -1;

    char surname1[25];
    char name1[10];
    char surname2[25];
    char name2[10];
    int a1[4];
    int a2[4];

    int f = 1;
    while (f == 1)
    {
        f = 0;
        if (fread(&stud, sizeof(struct Student), 1, file) <= 0)
            return -1;
        while (fread(&stud, sizeof(struct Student), 1, file) > 0)
        {
            fseek(file, -51-51, SEEK_CUR);
            fread(&surname1, sizeof(char), 25, file);
            fread(&name1, sizeof(char), 10, file);
            fread(&a1[4], sizeof(int), 16, file);
            fread(&surname2, sizeof(char), 25, file);
            fread(&name2, sizeof(char), 10, file);
            fread(&a2[4], sizeof(int), 16, file);

            if (strcmp(surname1, surname2) > 0 ||
                    (strcmp(surname1, surname2) == 0 && strcmp(name1, name2) > 0))
            {
                fseek(file, -51-51, SEEK_CUR);          //начало первой структуры surname1
                fwrite(&surname2, sizeof(char), 25, file);
                fwrite(&name2, sizeof(char), 10, file);
                fwrite(&a2[4], sizeof(int), 16, file);
                fwrite(&surname1, sizeof(char), 25, file);
                fwrite(&name1, sizeof(char), 10, file);
                fwrite(&a1[4], sizeof(int), 16, file);

                f = 1;
            }
        }
        fseek(file, 0, SEEK_SET);
    }

    rewind(file);
    while (fread(&stud, sizeof(struct Student), 1, file) > 0)
        {
            printf("%s%s%d%d%d%d\n",
                stud.Surname, stud.Name,
                stud.a[0], stud.a[1], stud.a[2], stud.a[3]);
        }

    fclose(file);
    return 0;
}


int b(char *fname, char *fname_out, char *str)
{
    FILE *file = fopen(fname, "rb");
    FILE *file_out = fopen(fname_out, "wb");
    struct Student stud;
    int len = strlen(str);
    char surname[25];
    char name[15];
    int a[4];

    if (!file)
        return -1;
    while (fread(&stud, sizeof(struct Student), 1, file) > 0)
    {
        fseek(file, -51, SEEK_CUR);
        fread(&surname, sizeof(char), 25, file);
        fread(&name, sizeof(char), 10, file);
        fread(&a[4], sizeof(int), 16, file);
        if (strncmp(surname, str, len) == 0)
        {
            fwrite(&surname, sizeof(char), 25, file_out);
            fwrite(&name, sizeof(char), 10, file_out);
            fwrite(&a[4], sizeof(int), 16, file_out);
        }
    }

    fclose(file);
    fclose(file_out);

    return 0;
}


int c(char *fname)
{
    FILE *file = fopen(fname, "r + b");
    struct Student stud;

    if (!file)
        return -1;
    while (fread(&stud, sizeof(struct Student), 1, file) > 0)
    {

    }
    return 0;
}


int main(int argc, char **argv)
{
    char *fname;
    char *fname_out;
    char *str;

    if (argc < 3)
        return -1;

    if (argc == 3)
    {
        fname = argv[2];
        if (strcmp(argv[1], "sb") == 0)
        {
            a(fname);
            return 0;
        }
        else if (strcmp(argv[1], "db") == 0)
        {
//            c(fname);
            return 0;
        }
        else
            return -1;
    }

    else if (argc == 5)
    {
        if (strcmp(argv[1], "fb") == 0)
        {
            fname = argv[2];
            fname_out = argv[3];
            str = argv[4];
//            b(fname, fname_out, str);
        }
        else
            return -1;
    }
    else
     return -1;


    return 0;
}
