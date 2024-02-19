#include <stdio.h>
#include "check_main.h"

//сравнение чисел по возрастанию
START_TEST(tests_compare_lower)
        {
                int first = 1;
                int second = 5;

                int *p_first = &first;
                int *p_second = &second;

                int result = comparator(p_first, p_second);
                ck_assert_int_eq(result, -4);
        }
END_TEST

//сравнение равных чисел
START_TEST(tests_compare_equal)
{
    int first = 5;
    int second = 5;

    int *p_first = &first;
    int *p_second = &second;

    int result = comparator(p_first, p_second);
    ck_assert_int_eq(result, 0);
}
END_TEST

//сравнение чисел по убыванию
START_TEST(tests_compare_bigger)
{
    int first = 5;
    int second = 1;

    int *p_first = &first;
    int *p_second = &second;

    int result = comparator(p_first, p_second);
    ck_assert_int_eq(result, 4);
}
END_TEST

        Suite *comparator_suite(void)
{
    Suite *s = suite_create("comparator");
    TCase *tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_compare_lower);
    tcase_add_test(tc_pos, tests_compare_equal);
    tcase_add_test(tc_pos, tests_compare_bigger);
    suite_add_tcase(s, tc_pos);

    return s;
}