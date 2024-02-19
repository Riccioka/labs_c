#include <stdio.h>
#include <check_main.h>
#include <check.h>

//проверка длины массива, состоящего из элементов меньше заданного значения price

//искомые элементы присутствуют в массиве
START_TEST(tests_find_arr_len_present)
{
    struct products arr[3];

    arr[0].price = 1;
    arr[1].price = 10;
    arr[2].price  = 20;

    int result = find_new_len(arr, 3, 20);
    ck_assert_int_eq(result, 2);
}
END_TEST

//искомые элементы отсутствуют в массиве
START_TEST(tests_find_arr_len_missing)
{
    struct products arr[3];

    arr[0].price = 1;
    arr[1].price = 10;
    arr[2].price  = 20;


    int result = find_new_len(arr, 3, 0);
    ck_assert_int_eq(result, 0);
}
END_TEST


START_TEST(tests_find_cheapest)
{
    int rc = 0;
    struct products arr[3];
    struct products new_arr[2];

    arr[0].price = 1;
    arr[1].price = 10;
    arr[2].price  = 20;

    find_cheapest(arr, 3, new_arr, 15);

    if (new_arr[0].price != 1 || new_arr[1].price != 10)
        rc = -1;

    ck_assert_int_eq(rc, 0);
}
END_TEST


Suite *find_suite(void)
{
    Suite *s = suite_create("find");
    TCase *tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_find_arr_len_missing);
    tcase_add_test(tc_pos, tests_find_cheapest);
    suite_add_tcase(s, tc_pos);

    TCase *tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_find_arr_len_present);
    suite_add_tcase(s, tc_neg);


    return s;
}