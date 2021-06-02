#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

typedef struct s_student
{
    char surname[25];
    char name[10];
    unsigned int a[4];
}				t_student;

void print_student(t_student *stud)
{
    if (stud)
    {
        double sum = stud->a[0] + stud->a[1] + stud->a[2] + stud->a[3];
        printf("%s %s %d %d %d %d - %lf\n",
        stud->surname, stud->name,
        stud->a[0], stud->a[1], stud->a[2], stud->a[3], sum / 4.0);
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
    printf("AVERAGE: %lf\n", average / count);
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

int sort(char **args)
{
    FILE *fin = fopen(args[2], "r+b");
    t_student s;
    t_student s2;
    int ret = -1;
    int rd = 0;
    size_t offset = 0;
    size_t current_pos = 0;

    memset(&s, 0, sizeof(s));
    memset(&s2, 0, sizeof(s2));
    if (fin)
    {
        ret = 0;
        while ((rd = fread(&s, sizeof(s), 1, fin)) || ret)
        {
            while ((rd = fread(&s2, sizeof(s2), 1, fin)) || ret)
            {
                if (student_cmp(&s, &s2))
                {
                    current_pos = ftell(fin) - sizeof(s2);
                    fseek(fin, offset, SEEK_SET);
                    if (!fwrite(&s2, sizeof(s2), 1, fin))
                        ret = -1;
                    fseek(fin, current_pos, SEEK_SET);
                    if (!ret && !fwrite(&s, sizeof(s), 1, fin))
                        ret = -1;
                    s = s2;
                }
            }
            offset += sizeof(s);
            fseek(fin, offset, SEEK_SET);
        }
        ret = -(!ret && rd == 0 && !feof(fin));
    }
    if (fin)
        fclose(fin);
    return ret;
}

int print(char **args)
{
    FILE *fin = fopen(args[2], "rb");
    FILE *fout = fopen(args[3], "wb");
    t_student s;
    int ret = -1;
    int rd = 0;

    memset(&s, 0, sizeof(s));
    if (fin && fout)
    {
        ret = 0;
        while ((rd = fread(&s, sizeof(s), 1, fin)) || ret)
        {
            if (strstr(s.surname, args[4]) == s.surname && !fwrite(&s, sizeof(s), 1, fout))
                ret = -1;
        }
        ret = -(!ret && rd == 0 && !feof(fin));
    }
    if (fin)
        fclose(fin);
    if (fout)
        fclose(fout);
    return ret;
}

double get_average(FILE *fin)
{
    double average = 0;
    size_t count = 0;
    t_student s;

    memset(&s, 0, sizeof(s));
    if (!fin)
        return 0;
    while (fread(&s, sizeof(s), 1, fin))
    {
        average += s.a[0] + s.a[1] + s.a[2] + s.a[3];
        count += 4;
    }
    return (feof(fin) && count) ? (average / count) : 0;
}

int del(char **args)
{
    FILE *fin = fopen(args[2], "r+b");
    double average = get_average(fin);
    t_student s;
    int ret = -1;
    int rd = 0;
    size_t offset = 0;
    size_t current_pos = 0;

    memset(&s, 0, sizeof(s));
    if (fin && average > 0.0)
    {
        fseek(fin, 0, SEEK_SET);
        ret = 0;
        while ((rd = fread(&s, sizeof(s), 1, fin)) || ret)
        {
            if ((s.a[0] + s.a[1] + s.a[2] + s.a[3]) / 4.0 >= average)
            {
                current_pos = ftell(fin);
                fseek(fin, offset, SEEK_SET);
                if (!fwrite(&s, sizeof(s), 1, fin))
                    ret = -1;
                offset += sizeof(s);
                fseek(fin, current_pos, SEEK_SET);
            }
        }
        ret = -(!ret && rd == 0 && !feof(fin));
    }

    if (fin)
    {
        fclose(fin);
        ret = truncate(args[2], offset);
    }
    return ret;
}

int extract_cmd(const char *arg)
{
    int ret = -53;
    int state = 0;

    while (*arg)
    {
        if ((*arg == 's' || *arg == 'f' || *arg == 'd') && state == 0)
        {
            state = 1;
            ret = 1 * (*arg == 'f') + 2 * (*arg == 'd');
        }
        else if (*arg == 'b' && state == 1)
            state = 2;
        ++arg;
    }
    return ret;
}

int main(int argc, char **argv)
{
    int ret = -53;
    int (*actions[])(char **) = { sort, print, del };

    if (argc > 2 && (ret = extract_cmd(argv[1])) >= 0
        && (argc == 3 || (argc == 5 && ret == 1)))
        ret = actions[ret](argv);
    return ret;
}
