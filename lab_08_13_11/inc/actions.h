#ifndef _MATRIX_FUNCS_H
#define _MATRIX_FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "struct_matrix.h"
#include "defines.h"
#include "memory_matrix.h"
#include "checks.h"

int sum_matrix(const matrix_t *mtr_1, const matrix_t *mtr_2, matrix_t *res);
//сумма матриц
//принимает на вход указатели на два слагаемых-матрицы и указатель на результирующую матрицу
//возвращает код ошибки

int multiplication_matrix(const matrix_t *mtr_1, const matrix_t *mtr_2, matrix_t *res);
//произведение матриц
//принимает на вход указатели на два множителя-матрицы и указатель на результирующую матрицу
//возвращает код ошибки

double delta_matrix(const matrix_t *mtr, int *rc);
//поиск определителя матрицы
//принимает на вход указатель на матрицу и код ошибки
//возвращает определитель матрицы

void get_matr(double **mas, double **p, int i, int j, int m);
//получение промежуточной матрицы (без i строки и j столбца)
//принимает на вход указатели на старую и новую матрицы, номер нужной строки i и столбца j, размер матрицы m
//возвращает код ошибки

#endif
