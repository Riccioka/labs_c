#include "actions.h"
#include "funcs_matrix.h"
#include "memory_matrix.h"

int sum_matrix(const matrix_t *mtr_1, const matrix_t *mtr_2, matrix_t *res)
{
    int rc = EXIT_SUCCESS;

    if (check_matrix_params(res) || !check_matrix_params(mtr_1) || !check_matrix_params(mtr_2))
        return PARAMS_ERROR;
    else
    {
        if (mtr_1->n != mtr_2->n || mtr_1->m != mtr_2->m)
            rc = SUM_ERROR;
        else
        {
            res->n = mtr_1->n;
            res->m = mtr_1->m;
            rc = allocate_matrix(res, res->n, res->m);

            if (res->matrix == NULL)
                return MEMORY_ERROR;
            else if (rc == 0)
                for (int i = 0; i < res->n; i++)
                    for (int j = 0; j < res->m; j++)
                        res->matrix[i][j] = mtr_1->matrix[i][j] + mtr_2->matrix[i][j];
        }
    }

    return rc;
}


int multiplication_matrix(const matrix_t *mtr_1, const matrix_t *mtr_2, matrix_t *res)
{
    int rc = EXIT_SUCCESS;
    if (check_matrix_params(res) || !check_matrix_params(mtr_1) || !check_matrix_params(mtr_2))
        rc = PARAMS_ERROR;
    else if (mtr_1->m == mtr_2->n && mtr_1->m > 0 && mtr_2->n)
    {
        rc = allocate_matrix(res, mtr_1->n, mtr_2->m);

        if (res->matrix == NULL)
            return MEMORY_ERROR;
        else if (rc == 0)
        {
            res->n = mtr_1->n;
            res->m = mtr_2->m;
            double multy = 0.0;

            for (int i = 0; i < res->n; i++)
                for (int j = 0; j < res->m; j++)
                {
                    for (int k = 0; k < mtr_2->n; k++)
                        multy += mtr_1->matrix[i][k] * mtr_2->matrix[k][j];
                    res->matrix[i][j] = multy;
                    multy = 0.0;
                }
        }
    }
    else
        rc = MULTI_ERROR;

    return rc;
}
//

double delta_matrix(const matrix_t *mtr, int *rc)
{
    double delta = 0;

    if (check_matrix_params(mtr) != 1 || mtr->m != mtr->n)
    {
        *rc = PARAMS_ERROR;
        return 0;
    }

    if (mtr->m == 1)
        delta = mtr->matrix[0][0];
    else if (mtr->m == 2)
        delta = mtr->matrix[0][0] * mtr->matrix[1][1] - (mtr->matrix[1][0] * mtr->matrix[0][1]);
    else if (mtr->m > 2)
    {
        matrix_t mtr_t;// = malloc(sizeof(matrix_t));
        int plus_saver = -1;

        default_matrix(&mtr_t);

        *rc = allocate_matrix(&mtr_t, mtr->n - 1, mtr->m - 1);
        if (mtr_t.matrix == NULL)
                return MEMORY_ERROR;
       
        if (*rc == 0)
        {
            for (int i = 0; i < mtr->m; i++)
            {
                get_matr(mtr->matrix, mtr_t.matrix, i, 0, mtr->m);
                plus_saver *= -1;
                delta += plus_saver * mtr->matrix[i][0] * delta_matrix(&mtr_t, rc);
            }
            free_matrix(&mtr_t);
        }
    }

    return delta;
}

void get_matr(double **mas, double **p, int i, int j, int m)
{
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki < m - 1; ki++)
    {
        if (ki == i)
            di = 1;
        dj = 0;
        for (kj = 0; kj < m - 1; kj++)
        {
            if (kj == j)
                dj = 1;
            p[ki][kj] = mas[ki + di][kj + dj];
        }
    }
}
