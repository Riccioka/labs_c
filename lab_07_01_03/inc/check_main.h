#ifndef _CHECK_MAIN_H_
#define _CHECK_MAIN_H_

#include <check.h>

#include "mysort.h"
#include "key.h"
#include "arr_and_file.h"

Suite *comparator_suite(void);
Suite *key_suite(void);
Suite *mysort_suite(void);

#endif