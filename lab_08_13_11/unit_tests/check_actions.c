#include <check_main.h>
#include <stdio.h>
#include "struct_matrix.h"
#include "actions.h"

START_TEST(sum_params_error_1)
{
    int rc = 0;
    matrix_t result, sum_1, sum_2;

    default_matrix(&sum_1);
    default_matrix(&sum_2);
    default_matrix(&result);

    rc = sum_matrix(&sum_1, &sum_2, &result);
    if (rc == PARAMS_ERROR)
        rc = -1;

    ck_assert_int_eq(rc, -1);
    free_matrix(&result);
}
END_TEST

START_TEST(sum_params_error_2)
{
    int rc = 0;
    matrix_t result, sum_1, sum_2;
    default_matrix(&sum_1);
    default_matrix(&sum_2);
    default_matrix(&result);

    rc = sum_matrix(&sum_1, &sum_2, &result);

    free_matrix(&result);
    result.m = 1;
    result.n = 1;

    rc = sum_matrix(&result, &sum_1, &sum_2);
    if (rc == PARAMS_ERROR)
        rc = -1;

    ck_assert_int_eq(rc, -1);
}
END_TEST


START_TEST(sum_error_3)
{
    int rc = 0;
    matrix_t result, sum_1, sum_2;
    default_matrix(&sum_1);
    default_matrix(&sum_2);
    default_matrix(&result);

    sum_1.n = 5;
    sum_1.m = 5;
    allocate_matrix(&sum_1, sum_1.n, sum_1.m);

    sum_2.n = 6;
    sum_2.m = 6;
    allocate_matrix(&sum_2, sum_2.n, sum_2.m);

    rc = sum_matrix(&sum_1, &sum_2, &result);
    if (rc == SUM_ERROR || result.matrix == NULL)
        rc = -1;

    free_matrix(&sum_1);
    free_matrix(&sum_2);
    free_matrix(&result);

    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(sum_pos_1)
{
    int rc = 0;
    matrix_t result, sum_1, sum_2;
    default_matrix(&result);
    default_matrix(&sum_1);
    default_matrix(&sum_2);

    sum_1.n = sum_2.n = 5;
    sum_1.m = sum_2.m = 5;

    allocate_matrix(&sum_1, sum_1.n, sum_1.m);
    allocate_matrix(&sum_2, sum_2.n, sum_2.m);

    for (int i = 0; i < sum_1.n; i++)
        for (int j = 0; j < sum_1.m; j++)
        {
            sum_1.matrix[i][j] = i + j;
            sum_2.matrix[i][j] = -(i + j);
        }

    rc = sum_matrix(&sum_1, &sum_2, &result);

    if (rc == 0)
    {
        for (int i = 0; i < sum_1.n && !rc; i++)
            for (int j = 0; j < sum_1.m && !rc; j++)
                if (fabs(result.matrix[i][j]) > EPS)
                    rc = -1;
    }
    else
        rc = -1;

    free_matrix(&sum_1);
    free_matrix(&sum_2);
    free_matrix(&result);


    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(sum_pos_2)
{
    int rc = 0;
    matrix_t result, sum_1, sum_2;
    default_matrix(&result);
    default_matrix(&sum_1);
    default_matrix(&sum_2);

    sum_1.n = sum_2.n = 10;
    sum_1.m = sum_2.m = 15;

    allocate_matrix(&sum_1, sum_1.n, sum_1.m);
    allocate_matrix(&sum_2, sum_2.n, sum_2.m);

    for (int i = 0; i < sum_1.n; i++)
        for (int j = 0; j < sum_1.m; j++)
        {
            sum_1.matrix[i][j] = i + j;
            sum_2.matrix[i][j] = -(i + j);
        }

    rc = sum_matrix(&sum_1, &sum_2, &result);

    if (rc == 0)
    {
        for (int i = 0; i < sum_1.n && !rc; i++)
            for (int j = 0; j < sum_1.m && !rc; j++)
                if (fabs(result.matrix[i][j]) > EPS)
                    rc = -1;
    }
    else
        rc = -1;

    free_matrix(&sum_1);
    free_matrix(&sum_2);
    free_matrix(&result);


    ck_assert_int_eq(rc, 0);
}
END_TEST


START_TEST(mul_params_error_1)
{
    int rc = 0;
    matrix_t result, sum_1, sum_2;
    default_matrix(&sum_1);
    default_matrix(&sum_2);
    default_matrix(&result);

    rc = multiplication_matrix(&sum_1, &sum_2, &result);
    if (rc == PARAMS_ERROR)
        rc = -1;

    ck_assert_int_eq(rc, -1);
    free_matrix(&result);
}
END_TEST

START_TEST(mul_params_error_2)
{
    int rc = 0;
    matrix_t result, sum_1, sum_2;
    default_matrix(&sum_1);
    default_matrix(&sum_2);
    default_matrix(&result);

    free_matrix(&result);
    result.m = 1;
    result.n = 1;

    rc = multiplication_matrix(&sum_1, &sum_2, &result);
    if (rc == PARAMS_ERROR)
        rc = -1;

    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(mul_error_3)
{
    int rc = 0;
    matrix_t result, sum_1, sum_2;
    default_matrix(&sum_1);
    default_matrix(&sum_2);
    default_matrix(&result);

    sum_1.n = 5;
    sum_1.m = 5;
    allocate_matrix(&sum_1, sum_1.n, sum_1.m);

    sum_2.n = 6;
    sum_2.m = 4;
    allocate_matrix(&sum_2, sum_2.n, sum_2.m);

    rc = multiplication_matrix(&sum_1, &sum_2, &result);
    if (rc == MULTI_ERROR || result.matrix == NULL)
        rc = -1;

    ck_assert_int_eq(rc, -1);

    free_matrix(&sum_1);
    free_matrix(&sum_2);
}
END_TEST

START_TEST(mul_pos_1)
{
    int rc = 0;
    matrix_t result, sum_1, sum_2;
    default_matrix(&sum_1);
    default_matrix(&sum_2);
    default_matrix(&result);

    sum_1.n = sum_2.n = 5;
    sum_1.m = sum_2.m = 5;

    allocate_matrix(&sum_1, sum_1.n, sum_1.m);
    allocate_matrix(&sum_2, sum_2.n, sum_2.m);

    for (int i = 0; i < sum_1.n; i++)
        for (int j = 0; j < sum_1.m; j++)
        {
            sum_1.matrix[i][j] = i + j;
            sum_2.matrix[i][j] = 0;
        }

    rc = multiplication_matrix(&sum_1, &sum_2, &result);

    if (rc == 0)
    {
        for (int i = 0; i < sum_1.n && !rc; i++)
            for (int j = 0; j < sum_1.m && !rc; j++)
                if (fabs(result.matrix[i][j]) > EPS)
                    rc = -1;
    }
    else
        rc = -1;

    free_matrix(&sum_1);
    free_matrix(&sum_2);
    free_matrix(&result);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(mul_pos_2)
{
    int rc = 0;
    matrix_t result, sum_1, sum_2;
    default_matrix(&sum_1);
    default_matrix(&sum_2);
    default_matrix(&result);

    sum_1.n = 6;
    sum_2.n = 5;
    sum_1.m = 5;
    sum_2.m = 7;

    allocate_matrix(&sum_1, sum_1.n, sum_1.m);
    allocate_matrix(&sum_2, sum_2.n, sum_2.m);

    for (int i = 0; i < sum_1.n; i++)
        for (int j = 0; j < sum_1.m; j++)
            sum_1.matrix[i][j] = i + j;

    for (int i = 0; i < sum_2.n; i++)
        for (int j = 0; j < sum_2.m; j++)
            sum_2.matrix[i][j] = 0;

    rc = multiplication_matrix(&sum_1, &sum_2, &result);

    if (rc == 0)
    {
        for (int i = 0; i < sum_1.n && !rc; i++)
            for (int j = 0; j < sum_1.m && !rc; j++)
                if (fabs(result.matrix[i][j]) > EPS)
                    rc = -1;
    }
    else
        rc = -1;

    free_matrix(&sum_1);
    free_matrix(&sum_2);
    free_matrix(&result);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(del_pos_1)
{
    int rc = 0;
    matrix_t mtr;
    default_matrix(&mtr);

    mtr.n = mtr.m = 1;

    allocate_matrix(&mtr, mtr.n, mtr.m);

    mtr.matrix[0][0] = 5;

    double res = delta_matrix(&mtr, &rc);

    if (res != 5 || rc != 0)
        rc = -1;

    ck_assert_int_eq(rc, 0);
    free_matrix(&mtr);
}
END_TEST

START_TEST(del_pos_2)
{
    int rc = 0;
    matrix_t mtr;
    default_matrix(&mtr);

    mtr.n = mtr.m = 2;

    allocate_matrix(&mtr, mtr.n, mtr.m);

    for (int i = 0; i < mtr.n; i++)
        for (int j = 0; j < mtr.m; j++)
            mtr.matrix[i][j] = i + j;

    double res = delta_matrix(&mtr, &rc);
//    printf("res = %f", res);

    if (res != -1 || rc != 0)
        rc = -1;

    ck_assert_int_eq(rc, 0);
    free_matrix(&mtr);
}
END_TEST

START_TEST(del_pos_3)
{
    int rc = 0;
    matrix_t mtr;
    default_matrix(&mtr);

    mtr.n = mtr.m = 5;

    allocate_matrix(&mtr, mtr.n, mtr.m);

    for (int i = 0; i < mtr.n; i++)
        for (int j = 0; j < mtr.m; j++)
            mtr.matrix[i][j] = i + j;

    double res = delta_matrix(&mtr, &rc);

    if (res != 0 || rc != 0)
        rc = -1;

    ck_assert_int_eq(rc, 0);
    free_matrix(&mtr);
}
END_TEST

START_TEST(del_params_error_1)
{
    int rc = 0;
    matrix_t mtr;
    default_matrix(&mtr);

    mtr.n = 3;
    mtr.m = 2;

    allocate_matrix(&mtr, mtr.n, mtr.m);

    for (int i = 0; i < mtr.n; i++)
        for (int j = 0; j < mtr.m; j++)
            mtr.matrix[i][j] = i + j;

    delta_matrix(&mtr, &rc);
//    printf("res = %f", res);

    if (rc == PARAMS_ERROR)
        rc = -1;

    ck_assert_int_eq(rc, -1);
    free_matrix(&mtr);
}
END_TEST

START_TEST(del_params_error_2)
{
    int rc = 0;
    matrix_t mtr;
    default_matrix(&mtr);

    mtr.n = mtr.m = 0;

    delta_matrix(&mtr, &rc);
//    printf("res = %f", res);

    if (rc == PARAMS_ERROR)
        rc = -1;

    ck_assert_int_eq(rc, -1);
    free_matrix(&mtr);
}
END_TEST

Suite *actions_suite(void)
{
    Suite *s = suite_create("actions");

    TCase *tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, sum_pos_1);
    tcase_add_test(tc_pos, sum_pos_2);
    tcase_add_test(tc_pos, mul_pos_1);
    tcase_add_test(tc_pos, mul_pos_2);
    tcase_add_test(tc_pos, del_pos_1);
    tcase_add_test(tc_pos, del_pos_2);
    tcase_add_test(tc_pos, del_pos_3);

    suite_add_tcase(s, tc_pos);

    TCase *tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, sum_params_error_1);
    tcase_add_test(tc_neg, sum_params_error_2);
    tcase_add_test(tc_neg, sum_error_3);
    tcase_add_test(tc_neg, mul_params_error_1);
    tcase_add_test(tc_neg, mul_params_error_2);
    tcase_add_test(tc_neg, mul_error_3);
    tcase_add_test(tc_neg, del_params_error_1);
    tcase_add_test(tc_neg, del_params_error_2);

    suite_add_tcase(s, tc_neg);

    return s;
}

