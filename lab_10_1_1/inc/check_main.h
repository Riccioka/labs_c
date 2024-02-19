#ifndef _CHECK_MAIN_H
#define _CHECK_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "checks.h"
#include "memory_countries.h"
#include "memory_list.h"

#include <check.h>

Suite *checks_suite(void);

Suite *list_operations_suite(void);

Suite *memory_countries_suite(void);

Suite *memory_list_suite(void);



#endif
