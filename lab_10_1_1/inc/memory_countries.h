#ifndef _MEMORY_COUNTRIES_H
#define _MEMORY_COUNTRIES_H

#include <stdio.h>
#include <stdlib.h>

#include "errors.h"
#include "structs.h"

char *allocate_name_str(int len);
//выделение памяти под строку
//принимает на вход длину строки
//возвращает указатель на строку

void free_name_str(char **str);
//освобождение памяти из под строки
//принимает на вход указатель на начало строки

country_t *allocate_struct_country(int size);
//выделение памяти под структуру
//принимает на вход размер
//возвращает указатель на структуру

void free_struct_country(country_t **data, int *n);
//освобождение памяти из под структуры
//принимает на вход указатель на структуру

#endif 