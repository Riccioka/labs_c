#ifndef _CHECKS_H
#define _CHECKS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct_matrix.h"
#include "defines.h"

int check_file(FILE *f);
//проверка файла на корректность
//принимает на вход указатель на файл
//возвращает код ошибки

int check_argc(int argc, char *action);
//проверка кол-ва аргументов и команды действия
//принимает на вход кол-во аргументов и символ действия
//возвращает код ошибки

int check_matrix_params(const matrix_t *matrix);
//проверка параметров матрицы
//принимает на вход указатель на матрицу
//возвращает код ошибки

#endif