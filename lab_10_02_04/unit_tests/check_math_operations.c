#include <check_main.h>
#include "math_operation_list.h"

START_TEST(num_in_list_neg_1)
{
    int n = 10;

    int rc = translate_num_in_list(NULL, n);
    if (rc == PARAMS_ERROR)
        rc = -1;

    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(num_in_list_neg_2)
{
    int n = 10;
    node_t *head = NULL;
    head = node_create(n + 1, 1);
    int rc = translate_num_in_list(&head, n);

    if (rc == PARAMS_ERROR)
        rc = -1;

    free_list(&head);

    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(num_in_list_neg_3)
{
    node_t *head = NULL;
    int n = -1;

    int rc = translate_num_in_list(&head, n);
    if (rc == TASK_ERROR)
        rc = -1;

    ck_assert_int_eq(rc, -1);
    free_list(&head);
}
END_TEST

START_TEST(list_in_num_neg_1)
{
    int rc = 0, n;

    rc = translate_list_in_num(NULL, &n);
    if (rc == PARAMS_ERROR)
        rc = -1;

    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(mul_neg_1)
{
    node_t *list_1 = NULL, *list_2 = NULL;
    int rc = multiply_lists(NULL, list_1, list_2);
    if (rc == PARAMS_ERROR)
        rc = -1;

    ck_assert_int_eq(rc, -1);

    free_list(&list_1);
    free_list(&list_2);
}
END_TEST

START_TEST(mul_neg_2)
{
    node_t *list_1 = NULL, *res = NULL;
    int rc = multiply_lists(&res, NULL, list_1);
    if (rc == PARAMS_ERROR)
        rc = -1;

    ck_assert_int_eq(rc, -1);

    free_list(&list_1);
    free_list(&res);
}
END_TEST

START_TEST(mul_neg_3)
{
    node_t *list_1 = NULL, *res = NULL;
    int rc = multiply_lists(&res, list_1, NULL);
    if (rc == PARAMS_ERROR)
        rc = -1;

    ck_assert_int_eq(rc, -1);

    free_list(&list_1);
    free_list(&res);
}
END_TEST

START_TEST(div_neg_1)
{
    node_t *list_1 = NULL, *list_2 = NULL;
    list_1 = node_create(1, 1);
    list_2 = node_create(2, 1);

    int rc = divide_lists(NULL, list_1, list_2);
    if (rc == PARAMS_ERROR)
        rc = -1;

    ck_assert_int_eq(rc, -1);

    free_list(&list_1);
    free_list(&list_2);
}
END_TEST

START_TEST(div_neg_2)
{
    node_t *list_1 = NULL, *res = NULL;
    list_1 = node_create(1, 1);

    int rc = divide_lists(&res, NULL, list_1);
    if (rc == PARAMS_ERROR)
        rc = -1;

    ck_assert_int_eq(rc, -1);

    free_list(&list_1);
    free_list(&res);
}
END_TEST

START_TEST(div_neg_3)
{
    node_t *list_1 = NULL, *res = NULL;
    list_1 = node_create(1, 1);

    int rc = divide_lists(&res, list_1, NULL);
    if (rc == PARAMS_ERROR)
        rc = -1;

    ck_assert_int_eq(rc, -1);

    free_list(&list_1);
    free_list(&res);
}
END_TEST

START_TEST(sqr_neg_1)
{
    node_t *list_1 = NULL;
    list_1 = node_create(2, 1);

    int rc = sqr_list(NULL, list_1);
    if (rc == PARAMS_ERROR)
        rc = -1;

    ck_assert_int_eq(rc, -1);

    free_list(&list_1);
}
END_TEST

START_TEST(sqr_neg_2)
{
    node_t *list_1 = NULL, *res = NULL;
    list_1 = node_create(2, 1);

    int rc = sqr_list(&res, NULL);
    if (rc == PARAMS_ERROR)
        rc = -1;

    ck_assert_int_eq(rc, -1);

    free_list(&list_1);
    free_list(&res);
}
END_TEST


START_TEST(num_in_list_pos_1)
{
    int rc = 0;
    node_t *head = NULL;
    int n = 10;

    rc = translate_num_in_list(&head, n);

    free_list(&head);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(num_in_list_pos_2)
{
    int rc = 0;
    node_t *head = NULL;
    int n = 16;

    rc = translate_num_in_list(&head, n);

    free_list(&head);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(mul_pos_1)
{
    int rc = 0;
    node_t *list_1 = NULL, *list_2 = NULL, *res = NULL;

    list_1 = node_create(1, 1);
    list_2 = node_create(2, 2);

    rc = multiply_lists(&res, list_1, list_2);
    if (rc != 0 || res->data != 2 || res->degree != 2)
        rc = -1;

    free_list(&list_1);
    free_list(&list_2);
    free_list(&res);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(mul_pos_2)
{
    int rc = 0;
    node_t *list_1 = NULL, *list_2 = NULL, *res = NULL;

    list_1 = node_create(5, 1);
    list_2 = node_create(2, 2);

    rc = multiply_lists(&res, list_1, list_2);

    node_t *current = res;

    if (rc != 0 || current->data != 5 || current->degree != 1)
        rc = -1;
    current = current->next;
    if (rc != 0 || current->data != 2 || current->degree != 2)
        rc = -1;

    free_list(&list_1);
    free_list(&list_2);
    free_list(&res);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(mul_pos_3)
{
    int rc = 0;
    node_t *list_1 = NULL, *list_2 = NULL, *res = NULL;

    list_1 = node_create(2, 5);
    list_2 = node_create(2, 2);

    rc = multiply_lists(&res, list_1, list_2);

    if (rc != 0 || res->data != 2 || res->degree != 7)
        rc = -1;

    free_list(&list_1);
    free_list(&list_2);
    free_list(&res);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(sqr_pos_1)
{
    int rc = 0;
    node_t *list_1 = NULL, *res = NULL;

    list_push_back(&list_1, 2, 1);

    rc = sqr_list(&res, list_1);
    if (rc != 0 || res->data != 2 || res->degree != 2)
        rc = -1;

    free_list(&list_1);
    free_list(&res);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(sqr_pos_2)
{
    int rc = 0;
    node_t *list_1 = NULL, *res = NULL;

    list_push_back(&list_1, 2, 4);

    rc = sqr_list(&res, list_1);
    if (rc != 0 || res->data != 2 || res->degree != 8)
        rc = -1;

    free_list(&list_1);
    free_list(&res);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(sqr_pos_3)
{
    int rc = 0;
    node_t *list_1 = NULL, *res = NULL;

    list_push_back(&list_1, 20, 1);

    rc = sqr_list(&res, list_1);
    node_t *current = res;

    if (rc != 0 || current->data != 5 || current->degree != 2)
        rc = -1;
    current = current->next;
    if (rc != 0 || current->data != 2 || current->degree != 4)
        rc = -1;

    free_list(&list_1);
    free_list(&res);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(div_pos_1)
{
    int rc = 0;
    node_t *list_1 = NULL, *list_2 = NULL, *res = NULL;

    list_1 = node_create(4, 2);
    list_2 = node_create(2, 1);

    rc = divide_lists(&res, list_1, list_2);
    if (rc != 0 || res->data != 2 || res->degree != 3)
        rc = -1;

    free_list(&list_1);
    free_list(&list_2);
    free_list(&res);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(div_pos_2)
{
    int rc = 0;
    node_t *list_1 = NULL, *list_2 = NULL, *res = NULL;

    list_1 = node_create(3, 4);
    list_2 = node_create(3, 1);

    rc = divide_lists(&res, list_1, list_2);
    if (rc != 0 || res->data != 3 || res->degree != 3)
        rc = -1;

    free_list(&list_1);
    free_list(&list_2);
    free_list(&res);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(div_pos_3)
{
    int rc = 0;
    node_t *list_1 = NULL, *list_2 = NULL, *res = NULL;

    list_1 = node_create(0, 1);
    list_2 = node_create(3, 4);

    rc = divide_lists(&res, list_1, list_2);
    if (rc != 0 || res->data != 0 || res->degree != 1)
        rc = -1;

    free_list(&list_1);
    free_list(&list_2);
    free_list(&res);

    ck_assert_int_eq(rc, -1);
}
END_TEST

Suite *math_operations_suite(void)
{
    Suite *s = suite_create("math_operations");

    TCase *tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, num_in_list_neg_1);
    tcase_add_test(tc_neg, num_in_list_neg_2);
    tcase_add_test(tc_neg, num_in_list_neg_3);
    tcase_add_test(tc_neg, list_in_num_neg_1);
    tcase_add_test(tc_neg, mul_neg_1);
    tcase_add_test(tc_neg, mul_neg_2);
    tcase_add_test(tc_neg, mul_neg_3);
    tcase_add_test(tc_neg, div_neg_1);
    tcase_add_test(tc_neg, div_neg_2);
    tcase_add_test(tc_neg, div_neg_3);
    tcase_add_test(tc_neg, sqr_neg_1);
    tcase_add_test(tc_neg, sqr_neg_2);

    suite_add_tcase(s, tc_neg);

    TCase *tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, num_in_list_pos_1);
    tcase_add_test(tc_pos, num_in_list_pos_2);
    tcase_add_test(tc_pos, mul_pos_1);
    tcase_add_test(tc_pos, mul_pos_2);
    tcase_add_test(tc_pos, mul_pos_3);
    tcase_add_test(tc_pos, sqr_pos_1);
    tcase_add_test(tc_pos, sqr_pos_2);
    tcase_add_test(tc_pos, sqr_pos_3);
    tcase_add_test(tc_pos, div_pos_1);
    tcase_add_test(tc_pos, div_pos_2);
    tcase_add_test(tc_pos, div_pos_3);

    suite_add_tcase(s, tc_pos);

    return s;
}

