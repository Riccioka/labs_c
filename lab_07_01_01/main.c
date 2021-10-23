#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "print_in_file.h"
#include "key.h"
#include "mysort.h"
#define INCORRECT_INPUT 1
#define NON_EXISTENT_FILE 2

int main(int argc, char **argv)
{
    int *arr;
    int count = 0, error = 0;
    if (argc != 3 && argc != 4)
        error = INCORRECT_INPUT;

    if (error == 0)
    {
        FILE *f_in = fopen(argv[1], "r");
        if (f_in == NULL)
            error = NON_EXISTENT_FILE;

        if (error == 0)
        {
            int el;
            while (fscanf(f_in, "%d", &el) != EOF)
                count += 1;

            arr = (int*)malloc(count * sizeof(int));

            rewind(f_in);

            for (int i = 0; i < count; i++)
               fscanf(f_in, "%d", &arr[i]);

            fclose(f_in);

            int *new_arr;
            int new_count = 0;

            setbuf(stdout, NULL);

            if (argc == 4 && strcmp(argv[3], "f") == 0)
            {
                new_count = key(arr, arr + count, &new_arr, (&new_arr + new_count));
//                mysort(new_count, &new_arr); // sizeof (int), (int(*) (const void *, const void *)) comp
                mysort(new_count, &new_arr, comparator);

                FILE *f_out = fopen(argv[2], "w");
                print_in_file(f_out, new_count, &new_arr);
                fclose(f_out);
            }
            else
            {
                mysort(count, &arr, comparator);

                FILE *f_out = fopen(argv[2], "w");
                print_in_file(f_out, count, &arr);
                fclose(f_out);
            }
        }
    }

    return error;
}
