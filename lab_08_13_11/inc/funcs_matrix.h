#ifndef _FUNCS_MATRIX_H
#define _FUNCS_MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#include "defines.h"
#include "struct_matrix.h"
#include "memory_matrix.h"

void default_matrix(matrix_t *matrix);
//инициализация матрицы
//принимает на вход указатель на матрицу

int fread_matrix(FILE *f, matrix_t *matrix);
//чтение матрицы
//принимает на вход указатель на файл и матрицу
//возвращает код ошибки

void fprint_matrix(FILE *f, const matrix_t *matrix);
//вывод матрицы
//принимает на вход указатель на файл и матрицу

void copy_matrix(matrix_t *dst, const matrix_t *src);
//создание копии матрицы
//принимает на вход указатель на матрицу dst, в которую копируется матрица src, и указатель на матрицу src

#endif
