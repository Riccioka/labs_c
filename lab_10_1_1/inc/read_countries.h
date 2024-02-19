#ifndef _READ_COUNTRIES_H
#define _READ_COUNTRIES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "memory_countries.h"
#include "checks.h"
#include "errors.h"

void default_country(country_t *country);
//инициализация одной структуры (страны)
//принимает на вход указатель на структуру

void default_array_country(countries_t *data);
//инициализация списка структур (страны)
//принимает на вход указатель на структуру

int get_size_string(FILE *f);
//поиск размера строки
//принимает на вход файл
//возвращает длину строки

int get_size_struct(FILE *f, size_t *size);
//поиск размера структур
//принимает на вход файл и переменную размера
//возвращает код ошибки

int fread_name_str(FILE *f, char **str, int size_str);
//чтение строки (имени или столицы страны)
//принимает на вход файл, указатель на строку и переменную ее размера
//возвращает код ошибки

int fread_country_info(FILE *f, country_t *country, size_t count_st);
//чтение данных структуры
//принимает на вход файл, указатель на структуру и переменную ее размера
//возвращает код ошибки

int fread_countries(FILE *f, country_t **data, int *n);
//чтение структур из файла
//принимает на вход файл, указатель на первую структуру и количество структур
//возвращает код ошибки

#endif 