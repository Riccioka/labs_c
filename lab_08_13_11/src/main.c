#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct_matrix.h"
#include "defines.h"
#include "memory_matrix.h"
#include "funcs_matrix.h"
#include "checks.h"
#include "actions.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = EXIT_SUCCESS;

    rc = check_argc(argc, argv[1]);

    if (rc != EXIT_SUCCESS)
        return rc;

    char *action = argv[1];
    if (argc == 5)
    {
        FILE *f_mtr_1 = NULL, *f_mtr_2 = NULL, *f_res = NULL;
        f_mtr_1 = fopen(argv[2], "r");
        rc = check_file(f_mtr_1);
        if (rc == EXIT_SUCCESS)
        {
            f_mtr_2 = fopen(argv[3], "r");
            rc = check_file(f_mtr_2);
            if (rc == EXIT_SUCCESS)
            {
                matrix_t matrix_1, matrix_2, result;
                default_matrix(&matrix_1);
                default_matrix(&matrix_2);
                default_matrix(&result);
                rc = fread_matrix(f_mtr_1, &matrix_1);
                if (rc == EXIT_SUCCESS)
                {
                    rc = fread_matrix(f_mtr_2, &matrix_2);
                    if (rc == EXIT_SUCCESS)
                    {
                        if (strcmp(action, "a") == 0)
                        {
                            rc = sum_matrix(&matrix_1, &matrix_2, &result);
                            if (rc == EXIT_SUCCESS)
                            {
                                f_res = fopen(argv[4], "w");
                                if (f_res != NULL)
                                {
                                    fprint_matrix(f_res, &result);
                                    fclose(f_res);
                                }
                                else
                                    rc = WRITE_ERROR;
                            }

                            free_matrix(&result);
                        }
                        else if (strcmp(action, "m") == 0)
                        {
                            rc = multiplication_matrix(&matrix_1, &matrix_2, &result);
                            if (rc == EXIT_SUCCESS)
                            {
                                f_res = fopen(argv[4], "w");
                                if (f_res != NULL)
                                {
                                    fprint_matrix(f_res, &result);
                                    fclose(f_res);
                                }
                                else
                                    rc = WRITE_ERROR;
                            }
                            free_matrix(&result);
                        }
                        else
                            rc = ACTION_ERROR;
                        free_matrix(&matrix_2);
                    }
                    free_matrix(&matrix_1);
                }
                fclose(f_mtr_2);
            }
            fclose(f_mtr_1);
        }
    }
    else if (argc == 4 && strcmp(action, "o") == 0)
    {
        FILE *f_mtr = NULL, *f_res = NULL;
        f_mtr = fopen(argv[2], "r");
        rc = check_file(f_mtr);
        if (rc == EXIT_SUCCESS)
        {
            matrix_t matrix;
            default_matrix(&matrix);

            rc = fread_matrix(f_mtr, &matrix);
            if (rc == EXIT_SUCCESS)
            {
                int rc_t = 0;
                double delta = delta_matrix(&matrix, &rc_t);
                if (rc_t == EXIT_SUCCESS)
                {
                    f_res = fopen(argv[3], "w");
                    fprintf(f_res, "%f\n", delta); //запись опр в файл
                    fclose(f_res);
                }
                else
                    rc = rc_t;
                free_matrix(&matrix);
            }

            
            fclose(f_mtr);
        }
    }
    else
        rc = ACTION_ERROR;

    return rc;
}
