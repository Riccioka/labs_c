#include "check_main.h"
#include <check.h>

int main(void)
{
    SRunner *runner = srunner_create(checks_suite());
    srunner_add_suite(runner, list_operations_suite());
    srunner_add_suite(runner, memory_countries_suite());
    srunner_add_suite(runner, memory_list_suite());

    srunner_run_all(runner, CK_VERBOSE);

    int num_of_fails = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (num_of_fails == 0)
        return 0;
    else
        return -1;
}