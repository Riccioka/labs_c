#ifndef _FIND_H_
#define _FIND_H_

#include "product.h"
#include <stdio.h>

void find_cheapest(struct products *struct_arr, int count, struct products *new_arr, float top_price);
//добавление в массив элементов с ценой ниже, чем top_price
//принимает на вход старый struct_arr и новый new_arr массив, кол-во элементов старого массива и максимальную стоимость

int find_name_len(FILE *f);
//определение длины строки(названия продукта),
//принимает на вход имя файла f, содержащего строку
//возвращает длину строки

int find_num_of_structs(FILE *f, int *structs_in_file);
//определение кол-ва структур в файле
//принимает на вход имя файла f и указатель на переменную кол-ва структур structs_in_file
//возвращает код ошибки

int find_new_len(struct products *struct_arr, int structs_num, int top_price);
//определение количество элементов с ценой ниже, чем top_price
//принимает на вход указатель на массив структур struct_arr, кол-во структур structs_num и максимальную стоимость top_price
//возвращает кол-во элементов

#endif
