#include <check_main.h>
#include "memory.h"

START_TEST(create_pos)
{
    int rc = 0;
    node_t *head = NULL;
    int n = 5;
    head = node_create(n, 3);
    if (head == NULL || head->data != n)
        rc = -1;

    free_list(&head);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(free_list_pos)
{
    int rc = 0;
    node_t *head = NULL;
    int n = 5;
    head = node_create(n, 1);
    free_list(&head);

    if (head != NULL)
        rc = -1;

    ck_assert_int_eq(rc, 0);
}
END_TEST


START_TEST(list_pb_neg)
{
    int n = 5;
    int rc = list_push_back(NULL, n, 1);
    if (rc != 0)
        rc = -1;

    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(list_pb_pos)
{
    node_t *head = NULL;
    int n = 5;
    int rc = list_push_back(&head, n, 1);
    if (rc != 0 || head->data == n)
        rc = -1;

    free_list(&head);

    ck_assert_int_eq(rc, -1);
}
END_TEST


START_TEST(alloc_str_pos)
{
    int rc = 0, n = 10;
    char *str = allocate_malloc_string(n);
    if (str == NULL)
        rc = -1;

    free_malloc_string(&str);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(free_str_pos)
{
    int rc = 0, n = 10;
    char *str = allocate_malloc_string(n);

    free_malloc_string(&str);
    if (str != NULL)
        rc = -1;

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(alloc_str_neg)
{
    int rc = 0, n = 0;
    char *str = allocate_malloc_string(n);
    if (str == NULL)
        rc = -1;

    ck_assert_int_eq(rc, -1);
    free_malloc_string(&str);
}
END_TEST

START_TEST(free_str_neg)
{
    int rc = 0, n = 0;
    char *str = allocate_malloc_string(n);

    free_malloc_string(&str);
    if (str == NULL)
        rc = -1;

    ck_assert_int_eq(rc, -1);
}
END_TEST

Suite *memory_suite(void)
{
    Suite *s = suite_create("memory");

    TCase *tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, list_pb_neg);
    tcase_add_test(tc_neg, alloc_str_neg);
    tcase_add_test(tc_neg, free_str_neg);

    suite_add_tcase(s, tc_neg);

    TCase *tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, create_pos);
    tcase_add_test(tc_pos, free_list_pos);
    tcase_add_test(tc_pos, list_pb_pos);
    tcase_add_test(tc_pos, alloc_str_pos);
    tcase_add_test(tc_pos, free_str_pos);

    suite_add_tcase(s, tc_pos);

    return s;
}