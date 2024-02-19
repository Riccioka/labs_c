#include <stdio.h>
#include "../inc/check_main.h"

//тест пустого после фильтрации массива
START_TEST(tests_key_empty_array)
        {
                int *pb_src, *pe_src, *pb_dst, *pe_dst;
                int array[] = {0};

                pb_src = array;
                pe_src = array;

                int result = key(pb_src, pe_src, &pb_dst, &pe_dst);
                ck_assert_int_eq(result, -1);
        }
END_TEST

//тест массива с одинаковыми элементами
START_TEST(tests_key_same_array)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int array[3] = {3, 3, 3};

    pb_src = array;
    pe_src = array + 3;

    int result = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(result, 0);

    free(pb_dst);
    ck_assert_ptr_nonnull(pb_dst);
}
END_TEST

//тест массива из двух элементов
START_TEST(tests_key_two_elems)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int array[2] = {1, 3};

    pb_src = array;
    pe_src = array + 1;

    int result = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(result, 0);
    free(pb_dst);
    ck_assert_ptr_nonnull(pb_dst);
}
END_TEST

//тест массива из положительных элементов
START_TEST(tests_key_normal)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int array[5] = {5, 1, 6, 9, 4};

    pb_src = array;
    pe_src = array + 4;

    int result = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(result, 0);
    ck_assert_ptr_nonnull(pb_dst);
    free(pb_dst);
}
END_TEST

//тест массива из отрицательных элементов
START_TEST(tests_key_normal_2)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int array[6] = {-5, -1, -6, -7, -9, -4};

    pb_src = array;
    pe_src = array + 5;

    int result = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(result, 0);
    ck_assert_ptr_nonnull(pb_dst);
    free(pb_dst);
}
END_TEST

        Suite *key_suite(void)
{
    Suite *s = suite_create("key");
    TCase *tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_key_empty_array);
    tcase_add_test(tc_pos, tests_key_same_array);
    tcase_add_test(tc_pos, tests_key_two_elems);
    tcase_add_test(tc_pos, tests_key_normal);
    tcase_add_test(tc_pos, tests_key_normal_2);
    suite_add_tcase(s, tc_pos);

    return s;
}
