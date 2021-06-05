#include <stdio.h>
#include <string.h>
#include "struct.h"

int bad_size(FILE *fp)
{
    fseek(fp, 0, SEEK_END);
    size_t size_file = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    return (size_file % sizeof(t_student));
}

void print_student(t_student *stud)
{
    if (stud)
    {
        printf("%s\n%s\n%d\n%d\n%d\n%d\n",
        // printf("%s %s %d %d %d %d\n",
        stud->surname, stud->name,
        stud->a[0], stud->a[1], stud->a[2], stud->a[3]);
    }
}

void print_students(FILE *fin)
{
    double average = 0;
    size_t count = 0;
    t_student stud;

    memset(&stud, 0, sizeof(stud));
    fseek(fin, 0, SEEK_SET);
    if (!fin)
        return;
    while (fread(&stud, sizeof(stud), 1, fin))
    {
        double sum = stud.a[0] + stud.a[1] + stud.a[2] + stud.a[3];
        average += sum;
        count += 4;
        print_student(&stud);
    }
    fseek(fin, 0, SEEK_SET);
}

int student_cmp(t_student *l, t_student *r)
{
    if (!l || !r)
        return 0;
    int s = strcmp(l->surname, r->surname);
    int n = strcmp(l->name, r->name);
    return (s > 0 || (s == 0 && n > 0));
}

int sort(char *args)
{
    FILE *fin = fopen(args, "r+b");
    t_student s;
    t_student s2;
    int ret = -1;
    int rd = 0;
    size_t offset = 0;
    size_t current_pos = 0;

    memset(&s, 0, sizeof(s));
    memset(&s2, 0, sizeof(s2));

    if (fin && !bad_size(fin))
    {
        ret = 0;
        while ((rd = fread(&s, sizeof(s), 1, fin)) && !ret)
        {
            while ((rd = fread(&s2, sizeof(s2), 1, fin)) && !ret)
            {
                if (student_cmp(&s, &s2))
                {
                    current_pos = ftell(fin) - sizeof(s2);
                    fseek(fin, offset, SEEK_SET);
                    fwrite(&s2, sizeof(s2), 1, fin);
                    fseek(fin, current_pos, SEEK_SET);
                    fwrite(&s, sizeof(s), 1, fin);
                    s = s2;
                }
            }
            offset += sizeof(s);
            fseek(fin, offset, SEEK_SET);
        }
        print_students(fin);
    }
    if (fin)
        fclose(fin);
    return ret;
}
