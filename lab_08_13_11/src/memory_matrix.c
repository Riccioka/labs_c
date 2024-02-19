#include "funcs_matrix.h"
#include "memory_matrix.h"

int allocate_matrix(matrix_t *matrix, int n, int m)
{
    if (!n || !m)
        return -1;

    matrix->matrix = NULL;
    matrix->n = 0;
    matrix->m = 0;

    double **data = calloc(n, sizeof (double*));
    if (data == NULL)
        return -1;

    for (int i = 0; i < n; i++)
    {
        data[i] = malloc(m * sizeof (double));
        if (!data[i])
        {
            for (int j = 0; j < i; j++)
                free(data[i]);
            free(data);
         //   free_matrix(data, n);
            return -1;
        }
    }

    matrix->matrix = data;
    matrix->n = n;
    matrix->m = m;

    return 0;
}

void free_matrix(matrix_t *m)
{
    if (!m->matrix)
        return;

    for (int i = 0; i < m->n; i++)
        free(m->matrix[i]);

    free(m->matrix);
    default_matrix(m);
}
