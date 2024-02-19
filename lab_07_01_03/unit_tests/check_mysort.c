#include <stdio.h>
#include "check_main.h"

//сортировка массива из одного элемента
START_TEST(tests_sort_one)
        {
                int array[1] = { 0 };

                mysort(array, 1, sizeof(int), comparator);
                ck_assert_int_eq(array[0], 0);
        }
END_TEST

//сортировка массива из положительных элементов
START_TEST(tests_sort_not_one)
{
    int array[4] = {3, 1, 0, 2};
    mysort(array, 4, sizeof(int), comparator);

    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 2);
    ck_assert_int_eq(array[3], 3);
}
END_TEST

//сортировка массива из положительных и отрицательных элементов
START_TEST(tests_sort_not_one_2)
{
    int array[4] = {3, 1, 0, -2};
    mysort(array, 4, sizeof(int), comparator);

    ck_assert_int_eq(array[0], -2);
    ck_assert_int_eq(array[1], 0);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 3);
}
END_TEST

        Suite *mysort_suite(void)
{
    Suite *s = suite_create("mysort");
    TCase *tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_sort_one);
    tcase_add_test(tc_pos, tests_sort_not_one);
    tcase_add_test(tc_pos, tests_sort_not_one_2);

    suite_add_tcase(s, tc_pos);

    return s;
}
