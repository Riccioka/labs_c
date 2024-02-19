#ifndef _CHECK_MEMORY_H
#define _CHECK_MEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_matrix.h"
#include "memory_matrix.h"
#include "funcs_matrix.h"

#include <check.h>

Suite *alloc_suite(void);

Suite *actions_suite(void);

#endif
