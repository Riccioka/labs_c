#include "check_main.h"
#include <check.h>

#define OK 0
#define ERR 1

int main(void)
{
    SRunner *runner = srunner_create(alloc_suite());
    srunner_add_suite(runner, actions_suite());

    srunner_run_all(runner, CK_VERBOSE);

    int num_of_fails = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (num_of_fails == 0)
        return 0;
    else
        return -1;
}