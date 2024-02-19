#ifndef _USE_FUNCS_H_
#define _USE_FUNCS_H_

#include <stdio.h>
#include "product.h"
#include "find.h"

int read_structs(FILE *f, struct products *struct_arr, int num_of_structs);
//чтение и инициализация массива структур
//принимает на вход имя файла f, указатель на массив структур struct_arr и кол-во структур num_of_structs
//возвращает код ошибки

int check_if_str_is_num(char *str);
//проверка строки на число
//принимает на вход указатель на строку str
//возвращает код ошибки

void free_all(struct products *struct_arr, struct products *new_arr, int structs_in_file);
//освобождение памяти
//принимает на вход указатель на массив структур struct_arr, кол-во структур structs_in_file и указатель на новый массив new_arr

#endif
