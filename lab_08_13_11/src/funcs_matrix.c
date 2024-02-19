#include "funcs_matrix.h"

void default_matrix(matrix_t *matrix)
{
    matrix->matrix = NULL;
    matrix->n = 0;
    matrix->m = 0;
}

int fread_matrix(FILE *f, matrix_t *matrix)
{
    int rc = EXIT_SUCCESS;
    if (f == NULL || matrix->n != 0 || matrix->m != 0)
        rc = PARAMS_ERROR;
    else
    {
        if (fscanf(f, "%d %d", &matrix->n, &matrix->m) != 2)
            rc = INVALID_ERROR;
        else if (matrix->n <= 0)
            rc = SIZE_N_ERROR;
        else if (matrix->m <= 0)
            rc = SIZE_M_ERROR;
        else
        {
            rc = allocate_matrix(matrix, matrix->n, matrix->m);
            if (matrix->matrix == NULL)
                rc = MEMORY_ERROR;
            else if (rc == 0)
            {
                int result = 0;
                for (int i = 0; i < matrix->n && rc == 0; i++)
                    for (int j = 0; j < matrix->m && rc == 0; j++)
                    {
                        result = fscanf(f, "%lf", &(matrix->matrix[i][j]));
                        if (result <= 0)
                        {
                            rc = INVALID_ERROR;
                            free_matrix(matrix);
                            return rc;
                        }
                    }
            }
            else
                free_matrix(matrix);
            double buff;
            if (f != stdin && fscanf(f, "%lf", &buff) == 1)
                rc = MATRIX_DATA_OVERFLOW;
        }
    }

    return rc;
}

void fprint_matrix(FILE *f, const matrix_t *matrix)
{
    fprintf(f, "%d %d\n", matrix->n, matrix->m);
    for (int i = 0; i < matrix->n; i++)
    {
        for (int j = 0; j < matrix->m; j++)
            fprintf(f, "%.6lf ", matrix->matrix[i][j]); // точность?
        fprintf(f, "\n");
    }
}

void copy_matrix(matrix_t *dst, const matrix_t *src)
{
    dst->n = src->n;
    dst->m = src->m;

    for (int i = 0; i < src->n; i++)
        for (int j = 0; j < src->m; j++)
            dst->matrix[i][j] = src->matrix[i][j];
}
