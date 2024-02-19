#include <check_main.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <check.h>

//проверка что строка состоит из чисел

//строка состоит только из чисел
START_TEST(tests_only_num)
{
    char *str = malloc(strlen("123") + 1 * sizeof(char));
    if (str)
        strcpy(str, "123");

    int result = check_if_str_is_num(str);
    ck_assert_int_eq(result, 0);

    free(str);
}
END_TEST

//строка состоит только из символов
START_TEST(tests_only_sym)
{
    char *str = malloc(strlen("kjh") + 1 * sizeof(char));
    if (str)
        strcpy(str, "kjh");

    int result = check_if_str_is_num(str);
    ck_assert_int_eq(result, -3);

    free(str);
}
END_TEST

//строка содержит в себе числа и символы
START_TEST(tests_sym_and_num)
{
    char *str = malloc(strlen("k2h") + 1 * sizeof(char));
    if (str)
        strcpy(str, "k2h");

    int result = check_if_str_is_num(str);
    ck_assert_int_eq(result, -3);

    free(str);
}
END_TEST

//строка состоит только из чисел и точек
START_TEST(tests_point_num)
{
    char *str = malloc(strlen("1.3") + 1 * sizeof(char));
    if (str)
        strcpy(str, "1.3");

    int result = check_if_str_is_num(str);
    ck_assert_int_eq(result, -3);

    free(str);
}
END_TEST

//
START_TEST(tests_free_all_er)
{
    int rc = 0;
    struct products *arr = NULL;
    struct products *new_arr = NULL;
    int structs_in_file = 2;

    free_all(arr, new_arr, structs_in_file);
    if (new_arr == NULL || arr == NULL)
        rc = -1;

    ck_assert_int_eq(rc, -1);
}
END_TEST

//START_TEST(tests_free_all_ok)
//{
//    int rc = 0;
//    struct products arr[2];
//    struct products new_arr[3];
//    int structs_in_file = 2;
//
//    for (int i = 0; i < structs_in_file; i++)
//    {
//        arr[i].price = i;
//        arr[i].name = "a";
//
//        new_arr[i].price = i - 1;
//        new_arr[i].name = "b";
//    }
//
//    free_all(arr, new_arr, structs_in_file);
//
//    if (new_arr == NULL || arr == NULL)
//        rc = -1;
//    ck_assert_int_eq(rc, 0);
//    free_all(arr, new_arr, structs_in_file);
//}
//END_TEST



        Suite *use_funcs_suite(void)
{
    Suite *s = suite_create("use_funcs");
    TCase *tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_only_num);
//    tcase_add_test(tc_pos, tests_free_all_ok);
    suite_add_tcase(s, tc_pos);

    TCase *tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_only_sym);
    tcase_add_test(tc_neg, tests_sym_and_num);
    tcase_add_test(tc_neg, tests_free_all_er);
    tcase_add_test(tc_pos, tests_point_num);
    suite_add_tcase(s, tc_neg);




    return s;
}
