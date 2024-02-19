#ifndef _PRINT_COUNTRIES_H
#define _PRINT_COUNTRIES_H

#include <stdio.h>
#include "structs.h"
#include "errors.h"

void fprint_country(FILE *f, country_t *country);
//запись одной структуры (страны) в файл
//принимает на вход файл и указатель на элемент

void fprint_countries(FILE *f, country_t *countries, int n);
//запись структур (стран) в файл
//принимает на вход файл и указатель на первый элемент

void print_error(int rc);
//вывод ошибки
//принимает на вход код ошибки

#endif