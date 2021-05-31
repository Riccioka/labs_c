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
    printf("LGjH");
    FILE *file = fopen(fname, "rb");
    struct Student stud;
    struct Student stud1, stud2;
    printf("LGBH");
    if (!file)
        return -1;

    int f = 1;
    while (f == 1)
    {
        f = 0;
        if (fread(&stud, sizeof(stud), 1, file) <= 0)
            return -1;
        while (fread(&stud, sizeof(stud), 1, file) > 0)
        {
            fseek(file, -51-51, SEEK_CUR);

            fread(&stud1, sizeof(stud), 1, file);
            fread(&stud2, sizeof(stud), 1, file);

            if (strcmp(stud1.Surname, stud2.Surname) > 0 ||
                    (strcmp(stud1.Surname, stud2.Surname) == 0 &&
                     strcmp(stud1.Name, stud2.Name) > 0))
            {
                fseek(file, -51-51, SEEK_CUR);
                fwrite(&stud2, sizeof(stud), 1, file);
                fwrite(&stud1, sizeof(stud), 1, file);

                f = 1;
            }
        }
        fseek(file, 0, SEEK_SET);
    }

    rewind(file);
    while (fread(&stud, sizeof(stud), 1, file) > 0)
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
//    char *fname_out;
//    char *str;

    if (argc < 3)
        return -1;

    printf("099");
    if (argc == 3)
    {
        fname = argv[2];
        if (strcmp(argv[1], "sb") == 0)
        {
            printf("df");
            a(fname);
            printf("yglkjhj");
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


//    else if (argc == 5)
//    {
//        if (strcmp(argv[1], "fb") == 0)
//        {
//            fname = argv[2];
//            fname_out = argv[3];
//            str = argv[4];
//            b(fname, fname_out, str);
//        }
//        else
//            return -1;
//    }
//    else
//     return -1;


    return 0;
}
