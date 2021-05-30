#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
}
