#include <check_main.h>
#include <stdio.h>
#include "struct_matrix.h"
#include "memory_matrix.h"

START_TEST(alloc_normal)
{
    matrix_t m;
    default_matrix(&m);
    int rc = allocate_matrix(&m, 2, 3);

    ck_assert_int_eq(rc, 0);
    free_matrix(&m);
}
END_TEST

START_TEST(free_normal)
{
    matrix_t m;
    default_matrix(&m);
    int rc = allocate_matrix(&m, 2, 3);

    free_matrix(&m);

    if (m.matrix != NULL)
        rc = -1;

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(alloc_neg)
{
    int rc = 0;
    matrix_t m;
    default_matrix(&m);
    if (allocate_matrix(&m, 0, 0) != 0)
        rc = -1;

    ck_assert_int_eq(rc, -1);
    free_matrix(&m);
}
END_TEST

START_TEST(free_neg)
{
    int rc = 0;
    matrix_t m;
    default_matrix(&m);
    rc = allocate_matrix(&m, 0, 0);
    free_matrix(&m);

    if (m.matrix != NULL)
        rc = -1;
    ck_assert_int_eq(rc, -1);
}
END_TEST

Suite *alloc_suite(void)
{
    Suite *s = suite_create("matrix_alloc");

    TCase *tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, alloc_normal);
    tcase_add_test(tc_pos, free_normal);

    suite_add_tcase(s, tc_pos);

    TCase *tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, alloc_neg);
    tcase_add_test(tc_neg, free_neg);

    suite_add_tcase(s, tc_neg);

    return s;
}


//matrix.n = 0;
//matrix.m = 0;
//matrix.matrix = (double **) allocate_matrix_third(0, 0);
//if (matrix.matrix != NULL)
//neg_cnt++;
//
//free_matrix_third(&matrix.matrix);
//if (matrix.matrix != NULL)
//neg_cnt++;
//}