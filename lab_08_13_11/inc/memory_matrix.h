#ifndef _MEMORY_MATRIX_H
#define _MEMORY_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include "struct_matrix.h"

int allocate_matrix(matrix_t *matrix, int n, int m);
//выделение памяти под матрицу
//принимает на вход указатель на матрицу, кол-во строк n и кол-во столбцов m
//возвращает код ошибки

void free_matrix(matrix_t *m);
//освобождение памяти матрицы
//принимает на вход указатель на матрицу

#endif
